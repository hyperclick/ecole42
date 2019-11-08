/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:49:07 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:49:09 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	print_usage(const char f)
{
	ft_putstr_fd("ls: illegal option -- ", STDERR_FILENO);
	ft_putchar_fd(f, STDERR_FILENO);
	ft_putstr_fd("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", STDERR_FILENO);
}

void	print_no_such_file(const char arg[])
{
	ft_putstr_fd("ls: ", STDERR_FILENO);
	ft_putstr_fd(*arg == 0 ? "fts_open" : arg, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	if (*arg == 0)
	{
		exit(1);
	}
}

void	print_no_such_files(char *files[], int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		print_no_such_file(files[i]);
	}
}

BOOL	parse_flag(t_input *input, const char f)
{
	if (f == 'l')
	{
		input->print_options.details = TRUE;
		input->print_options.single_column = FALSE;
		return (TRUE);
	}
	if (f == '1')
	{
		input->print_options.single_column = TRUE;
		input->print_options.details = FALSE;
		return (TRUE);
	}
	if (f == 'a')
	{
		input->find_options.all = TRUE;
		return (TRUE);
	}
	if (f == 'R')
	{
		input->find_options.recursive = TRUE;
		return (TRUE);
	}
	if (f == 'r')
	{
		input->sort_options.sort_desc = TRUE;
		return (TRUE);
	}
	if (f == 't')
	{
		input->sort_options.sort_by = SORT_BY_MOD_TIME;
		return (TRUE);
	}
	if (f == 'T')
	{
		input->print_options.long_datetime = TRUE;
		return (TRUE);
	}
	print_usage(f);
	exit (1);
	return (FALSE);
}

BOOL	try_parse_option(t_input *input, const char arg[])
{
	while (*arg != 0)
	{
		if (!parse_flag(input, *arg))
		{
			return (FALSE);
		}
		++arg;
	}
	return (TRUE);
}

void	parse_arguments_add_entry(t_input *input, t_entry e)
{
	if (is_folder(e.s.st_mode))
	{
		input->folders[input->folders_count++] = e;
		if (input->folders_count > MAX_FSO_IN_DIR)
		{
			ft_putstr("MAX_FSO_IN_DIR reached \n");
			exit(3);
		}
	}
	else
	{
		input->files[input->files_count++] = e;
		if (input->files_count > MAX_FSO_IN_DIR)
		{
			ft_putstr("MAX_FSO_IN_DIR reached \n");
			exit(4);
		}
	}
}

t_input	create_empty_input()
{
	t_input input;

	input.files_count = 0;
	input.folders_count = 0;
	input.args_count = 0;
	input.sort_options.sort_by = SORT_BY_NAME;
	input.sort_options.sort_desc = FALSE;
	return (input);
}

static void	remove_file(t_input *input, int n)
{
	input->files_count--;
	while (n < input->files_count )
	{
		input->files[n] = input->files[n + 1];
		n++;
	}
}

static void process_links(t_input *input)
{
	int		i;
	BOOL	link_found;

	if (input->print_options.details)
	{
		return ;
	}
	link_found = TRUE;
	while(link_found)
	{
		link_found = FALSE;
		i = -1;
		while (++i < input->files_count)
		{
			if (is_link(input->files[i].s.st_mode))
			{
				t_entry t = try_get_target_entry(input->files[i].full_name.path);
				if (is_folder(t.s.st_mode))
				{
					t.full_name = input->files[i].full_name;
					parse_arguments_add_entry(input, t);
					remove_file(input, i);
					link_found = TRUE;
					break;
				}
				
			}
		}
	}
}

t_input	parse_arguments(int c, const char *args[])
{
	t_input		input;
	const char	*arg;
	BOOL		parsing_options;
	t_entry		e;
	BOOL		entry_provided;
	char		*missing_entries[c + 1];
	int			missing_entries_count = 0;

	parsing_options = TRUE;
	input = create_empty_input();
	entry_provided = FALSE;
	for (int i = 0; i < c; i++)
	{
		arg = args[i];
		//options are coming before files
		if (parsing_options && ft_strcmp("--", arg) == 0 )
		{
			parsing_options = FALSE;
			continue;
		}
		if ((parsing_options && arg[0] != '-') || ft_strcmp("-", arg) == 0)
		{
			parsing_options = FALSE;
		}
		if (parsing_options)
		{
			if (try_parse_option(&input, arg + 1))
			{
				continue;
			}
		}
		entry_provided = TRUE;
		input.args_count++;
		e = try_get_entry(arg);
		if (is_null_entry(e))
		{
			missing_entries[missing_entries_count++] = ft_strdup(arg);
			continue;
		}
		//if (is_folder(e.s.st_mode))
		{
			ft_strcpy(e.full_name.name, arg);
		}
		parse_arguments_add_entry(&input, e);
	}
	ft_sort_strings(missing_entries, missing_entries_count);
	print_no_such_files(missing_entries, missing_entries_count);
	while (missing_entries_count-- > 0)
	{
		free(missing_entries[missing_entries_count]);
	}
	
	process_links(&input);
	
	if (entry_provided == FALSE && input.files_count == 0 && input.folders_count == 0)
	{
		log_line("no files or folders provided. using .");
		t_entry e = try_get_entry(".");
		if (is_null_entry(e))
		{
			ft_putstr("failed to create entry for '.'\n");
			exit(5);
		}
		parse_arguments_add_entry(&input, e);
	}
	
	return (input);
}

