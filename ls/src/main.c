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
		if (is_folder(e.s.st_mode))
		{
			ft_putstr("\n");
			ft_putstr(e.full_name.path);
			ft_putstr(":\n");
			print_folder_recursive(e, input);
		}
	}
}

void	log_entries(t_entry entries[], int count)
{
	int	i;
	
	i = -1;
	while (++i < count)
	{
		log_line(entries[i].full_name.name);
	}
}

void		print_folders(t_entry folders[], int count, t_input input)
{
	for ( int i = 0; i < count; i++)
	{
		if (i > 0 || input.files_count > 0)
		{
			ft_putchar('\n');
		}
		if (count != 1)
		{
			ft_putstr(folders[i].full_name.name);
			ft_putstr(":\n");
		}
		if (input.find_options.recursive)
		{
			print_folder_recursive(folders[i], input);
		}
		else
		{
			t_entry	entries[MAX_FSO_IN_DIR];
			int entries_count = get_folder_entries(entries, folders[i], input.find_options);
			log_log("entries found in ");
			log_line(folders[i].full_name.path);
			log_entries(entries, entries_count);
			print_folder_entries(entries, entries_count, input);
		}
	}
}

void	log_input(t_input input)
{
	int	i;

	log_line("arguments parsed:");
	log_line("files:");
	
	i = -1;
	while (++i < input.files_count)
	{
		log_line(input.files[i].full_name.path);
	}
	log_line("folders:");
	
	i = -1;
	while (++i < input.folders_count)
	{
		log_line(input.folders[i].full_name.path);
	}
}

int	main(int argc, const char* argv[])
{
	log_line("\n\n\n---------------started----------------");
	//log_args
	log_line(argv[0]);
	/*
	if (ft_starts_with_string(argv[0], "./ft_ls"))
	{
		<#statements#>
	}*/
	//t_entry	app = try_get_entry(argv[0]);
	//t_entry	app = try_get_entry(".");
	//input.cur_dir = try_get_entry(argv[0]);
	//set_cur_dir(app.full_name.folder);
	//log_log("cur_dir is:\t");
	//log_line(get_cur_dir().full_name.path);
	t_input input = parse_arguments(argc - 1, argv + 1);
	log_input(input);
	print_entries(sort(input.files, input.files_count, input.sort_options), input.files_count, input.print_options);
	print_folders(sort(input.folders, input.folders_count, input.sort_options), input.folders_count, input);
	return (0);
}
