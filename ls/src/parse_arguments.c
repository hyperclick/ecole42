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
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
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
	if (f == '1')
	{
		input->print_options.single_column = TRUE;
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

t_input	parse_arguments(int c, const char *args[])
{
	t_input		input;
	const char	*arg;
	BOOL		parsing_options;
	t_entry		e;
	BOOL		entry_provided;
	char		*missing_entries[c];
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
		parse_arguments_add_entry(&input, e);
	}
	ft_sort_strings(missing_entries, missing_entries_count);
	print_no_such_files(missing_entries, missing_entries_count);
	while (missing_entries_count-- > 0)
	{
		free(missing_entries[missing_entries_count]);
	}
	
	if (entry_provided == FALSE && input.files_count == 0 && input.folders_count == 0)
	{
		log_line("no files or folders provided. using .");
		t_entry e = try_get_entry(".");
		if (is_null_entry(e))
		{
			ft_putstr("failed to create entry for '.'\n");
			exit(5);
		}
		//ft_putstr("qqq");
		parse_arguments_add_entry(&input, e);
	}
	
	return (input);
}
