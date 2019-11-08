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

BOOL			try_parse_option(t_input *input, const char arg[])
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


BOOL		parse_option(const char *arg, t_input *input, BOOL *parsing_options)
{
	if (ft_strcmp("-", arg) == 0)
	{
		*parsing_options = FALSE;
		return (FALSE);
	}
	if (ft_strcmp("--", arg) == 0)
	{
		*parsing_options = FALSE;
		return (TRUE);
	}
	if ((arg[0] != '-'))
	{
		*parsing_options = FALSE;
	}
	if (*parsing_options)
	{
		if (try_parse_option(input, arg + 1))
		{
			return (TRUE);
		}
	}
	return (FALSE);
}

static BOOL		process_args(
				struct s_parse_params *p, char *missing_entries[])
{
	BOOL		entry_provided;
	int			i;
	BOOL		parsing_options;
	t_entry		e;

	p->missing_entries_count = 0;
	entry_provided = FALSE;
	parsing_options = TRUE;
	i = -1;
	while (++i < p->count)
	{
		if ((parsing_options))
			if (parse_option(p->args[i], p->input, &parsing_options))
				continue;
		entry_provided = TRUE;
		p->input->args_count++;
		if (is_null_entry((e = try_get_entry(p->args[i]))))
		{
			missing_entries[p->missing_entries_count++] = ft_strdup(p->args[i]);
			continue;
		}
		ft_strcpy(e.full_name.name, p->args[i]);
		parse_arguments_add_entry(p->input, e);
	}
	return (entry_provided);
}

static BOOL		parse_options_and_entries(
	const char **args, int count, t_input *input)
{
	BOOL		entry_provided;
	char		*missing_entries[count + 1];
	struct s_parse_params	params;

	params.args = args;
	params.count = count;
	params.input = input;
	params.missing_entries_count = 0;
	entry_provided = process_args(&params, missing_entries);
	ft_sort_strings(missing_entries, params.missing_entries_count);
	print_no_such_files(missing_entries, params.missing_entries_count);
	while (params.missing_entries_count-- > 0)
	{
		free(missing_entries[params.missing_entries_count]);
	}
	return (entry_provided);
}

t_input			parse_arguments(int c, const char *args[])
{
	t_input		input;
	BOOL		entry_provided;
	t_entry		e;

	input = create_empty_input();
	entry_provided = parse_options_and_entries(args, c, &input);
	process_links(&input);
	if (entry_provided == FALSE
		&& input.files_count == 0
		&& input.folders_count == 0)
	{
		log_line("no files or folders provided. using .");
		e = try_get_entry(".");
		if (is_null_entry(e))
		{
			ft_putstr("failed to create entry for '.'\n");
			exit(5);
		}
		parse_arguments_add_entry(&input, e);
	}
	return (input);
}
