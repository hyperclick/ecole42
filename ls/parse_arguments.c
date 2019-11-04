#include "ls.h"
void	print_usage()
{
	ft_putstr("ls: illegal option -- ?\n");
	ft_putstr("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]");
	
}

void	print_no_such_file(const char    arg[])
{
	printf("ls: cannot access '%s': No such file or directory\n", arg);
}

BOOL	parse_flag(t_input *input, const char f)
{
	if (f == 'l')
	{
		input->print_options.one_file_per_line = TRUE;
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
			printf("MAX_FSO_IN_DIR reached \n");
			exit(3);
		}
	}
	else
	{
		input->files[input->files_count++] = e;
		if (input->files_count > MAX_FSO_IN_DIR)
		{
			printf("MAX_FSO_IN_DIR reached \n");
			exit(4);
		}
	}
}

t_input	create_empty_input()
{
	t_input input;
	input.files_count = 0;
	input.folders_count = 0;
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

	parsing_options = TRUE;
	input = create_empty_input();
	
	//options are coming before files
	
	for (int i = 0; i < c; i++)
	{
		arg = args[i];
		if (parsing_options && arg[0] != '-')
		{
			parsing_options = FALSE;
		}
		if (parsing_options)
		{
			if (try_parse_option(&input, arg + 1))
			{
				continue;
			}
			print_usage();
			exit (1);
		}
		e = try_get_entry(arg);
		if (is_null_entry(e))
		{
			print_no_such_file(arg);
			continue;
		}
		parse_arguments_add_entry(&input, e);
	}
	return (input);
}

