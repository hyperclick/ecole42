#include "ls.h"


void	print_folder_entries(t_entry entries[MAX_FSO_IN_DIR], int count, t_input input)
{
	sort(entries, count, input.sort_options);
	//print_folder_header(folder, input.print_options);
	print_entries(entries, count, input.print_options);
}

void		print_folder_recursive(t_entry folder, t_input input)
{
	t_entry	entries[MAX_FSO_IN_DIR];
	int count = get_folder_entries(entries, folder, input.find_options);
	print_folder_entries(entries, count, input);
	for (int i = 0; i < count; i++)
	{
		t_entry e = entries[i];
		if (e.is_folder)
		{
			print_folder_recursive(e, input);
		}
	}
}

void		print_folders(t_entry folders[], int count, t_input input)
{
	for ( int i = 0; i < count; i++)
	{
		if (input.find_options.recursive)
			{
			print_folder_recursive(folders[i], input);
			}
			else
			{
				t_entry	entries[MAX_FSO_IN_DIR];
				int entries_count = get_folder_entries(entries, folders[i], input.find_options);
				print_folder_entries(entries, entries_count, input);
			}
	}
}


int	main2(int argc, const char* argv[])
{
	//input.cur_dir = try_get_entry(argv[0]);
	set_cur_dir(argv[0]);	t_input input = parse_arguments(argc - 1, argv + 1);
	if (input.files_count == 0 && input.folders_count == 0)
	{
		
		t_entry e = try_get_entry(".");
		if (is_null_entry(e))
		{
			ft_putstr("failed to create entry for '.'\n");
			exit(5);
		}
		parse_arguments_add_entry(&input, e);
	}
	print_entries(sort(input.files, input.files_count, input.sort_options), input.files_count, input.print_options);
	print_folders(sort(input.folders, input.folders_count, input.sort_options), input.folders_count, input);
	return (0);
}
