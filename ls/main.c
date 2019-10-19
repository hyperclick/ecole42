#include "ls.h"


void		print_folder_recursive(t_entry folder, t_input input)
{
	t_entry	entries[MAX_FSO_IN_DIR];
	int count = get_folder_entries(folder, input.find_options);
	sort(entries, count, input.sort_options);
	//print_folder_header(folder, input.print_options);
	print_entries(entries, count, input.print_options);

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
	if (input.find_options.recursive)
	{
		for each (t_entry folder in folders)
		{
			print_folder_recursive(folder, input);
		}
	}
	else
	{
		print_entries(folders, count, input.print_options);
	}
}


int	main(int argc, const char* argv[])
{
	t_input input = parse_arguments(argc - 1, argv + 1);
	//input.cur_dir = get_folder(argv[0]);
	print_entries(sort(input.files, input.files_count, input.sort_options), input.files_count, input.print_options);
	print_folders(sort(input.folders, input.folders_count, input.sort_options), input);

}