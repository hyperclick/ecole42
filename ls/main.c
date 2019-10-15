#include "ls.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/xattr.h>
#define XATTR_SIZE 10000

typedef struct s_full_name
{
	char		path[MAX_PATH];
	char		folder[MAX_PATH];
	char		name[MAX_PATH];
}					t_f_n;
typedef	struct s_entry
{
	t_f_n	full_name;
	BOOL		is_folder;
}				t_entry;

typedef	struct s_input
{
	t_entry files[MAX_FILES];
	t_entry folders[MAX_FOLDERS];
	t_find_ptions	find_options;
	t_sort_options	sort_options;
	t_print_options	print_options;
}	t_input;

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

int	main(int argc, const char* argv[])
{
	t_input input = parse_arguments(argc - 1, argv + 1);
	//input.cur_dir = get_folder(argv[0]);
	print_entries(sort(input.files, input.sort_options), input.print_options);
	print_folders(sort(input.folders, input.sort_options), input);
}