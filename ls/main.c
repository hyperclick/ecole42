#include "ls.h"

void		print_entries(t_entry	entries[MAX_FSO_IN_DIR], t_print_options o)
{
	int	cols_count = get_columns_count(o);
	int	rows_count = get_rows_count(entries, cols_count);
	for (int i = 0; i < rows_count; i++)
	{
		for (int j = 0; j < cols_count; j++)
		{
			print(entries[i * cols_count + j], o);
		}
		ft_putstr('\n');
	}
}

void		get_folder_entries(t_entry entries[], t_input folder, t_find_options o)
{

	DIR* dir;
	struct dirent* entry;
	dir = opendir(folder);
	if (!dir)
	{
		//todo: compare with ls output
		perror("diropen");
		return;
	};


	while ((entry = readdir(dir)) != NULL)
	{
		if (need_to_show(entry, o))
		{
			entries[i++] = make_entry(folder, entry);
		}
		free(entry);
	};

	closedir(dir);
	free(dir);
}

void		print_folder_recursive(t_entry folder, t_input input)
{
	t_entry	entries[MAX_FSO_IN_DIR] = sort(get_folder_entries(folder, input.find_options), input.sort_options);
	print_folder_header(folder, input.print_options);
	print_entries(entries, input.print_options);

	for each (t_entry e in entries)
	{
		if (e.is_folder)
		{
			print_folder_recursive(folder, input);
		}
	}
}

void		print_folders(t_entry folders[], t_input input)
{
	for each (t_entry folder in folders)
	{
		print_folder_recursive(folder, input);
	}
}

int need_to_show(const char name[])
{
	return (1);
}
void    print_usage()
{}
void    print_no_such_file(const char    arg[])
{
	printf("ls: cannot access '%s': No such file or directory\n", arg);
}
BOOL    try_parse_option(t_input input, const char    arg[])
{
	return (TRUE);
}
t_entry create_null_entry()
{
	t_entry e;
	e.is_null = TRUE;
	return (e);
}
t_f_n    get_full_name(const char name[])
{
	t_f_n   fn;

	return (fn);
}
void    fill_entry_dir(t_entry e, struct stat s, const char name[])
{
	t_f_n   fn;
	e.is_folder = TRUE;
	e.full_name = get_full_name(name);
	e.is_null = FALSE;
}

void fill_entry(t_entry e, struct stat s, const char name[])
{

	switch (s.st_mode & S_IFMT) {
	case S_IFBLK:  printf("block device:\tignoring\n");            break;
	case S_IFCHR:  printf("character device\tignoring\n");        break;
	case S_IFDIR:  fill_entry_dir(e, s, name);          break;
	case S_IFIFO:  printf("FIFO/pipe\tignoring\n");               break;
	case S_IFLNK:  printf("symlink\n");                 break;
	case S_IFREG:  printf("regular file\n");            break;
	case S_IFSOCK: printf("socket\tignoring\n");                  break;
	default:       printf("unknown?: %d\n", s.st_mode);   exit(2);             break;
	}


}

t_entry try_get_entry(const char    arg[])
{
	t_entry e;
	e = create_null_entry();

	struct stat s;
	if (lstat(arg, &s) != -1)
	{
		fill_entry(e, s, arg);
	}
	return (e);
}

void     parse_arguments_add_entry(t_input input, t_entry e)
{
	if (e.is_folder)
	{
		input.folders[input.folders_count++] = e;
		if (input.folders_count > MAX_FSO_IN_DIR)
		{
			printf("MAX_FSO_IN_DIR reached \n");
			exit(3);
		}
	}
	else
	{
		input.files[input.files_count++] = e;
		if (input.files_count > MAX_FSO_IN_DIR)
		{
			printf("MAX_FSO_IN_DIR reached \n");
			exit(4);
		}
	}
}
t_input create_empty_input()
{
	t_input input;
	input.files_count = 0;
	input.folders_count = 0;
	return (input);
}
t_input	parse_arguments(int c, char* args[])
{
	t_input input;
	char* arg;

	input = create_empty_input();

	for (int i = 0; i < c; i++)
	{
		arg = args[i];
		t_entry e = try_get_entry(arg);
		if (!is_null_entry(e))
		{
			parse_arguments_add_entry(input, e);
			continue;
		}
		if (arg[0] != '-')
		{
			print_no_such_file(arg);
			continue;
		}
		if (!try_parse_option(input, arg))
		{
			print_usage();
			exit(1);
		}
	}
	return (input);
}

int	main(int argc, const char* argv[])
{
	t_input input = parse_arguments(argc - 1, argv + 1);
	//input.cur_dir = get_folder(argv[0]);
	print_entries(sort(input.files, input.sort_options), input.print_options);
	print_folders(sort(input.folders, input.sort_options), input);
}