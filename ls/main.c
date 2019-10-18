#include "ls.h"


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
	print_entries(sort(input.files, input.sort_options), input.files_count, input.print_options);
	//print_folders(sort(input.folders, input.sort_options), input);

}