#include "ls.h"

BOOL	is_cur_dir(const char name[])
{
	return (ft_strcmp(name, ".") == 0);
}
BOOL	is_parent_dir(const char name[])
{
	return (ft_strcmp(name, "..") == 0);
}

int		calc_total(t_entry	entries[MAX_FSO_IN_DIR], int count)
{
	int	total = 0;
	for (int j = 0; j < count; j++)
	{
		total += entries[j].s.st_blocks;
	}
	return (total);
}

void	print_folder_entries(t_entry entries[MAX_FSO_IN_DIR], int count, t_input input)
{
	sort(entries, count, input.sort_options);
	//print_folder_header(folder, input.print_options);
	if (input.print_options.details && count != 0)
	{
		ft_putstr("total ");
		ft_putnbr(calc_total(entries, count));
		ft_putstr("\n");
	}
	print_entries(entries, count, input.print_options);
}

void		move_array(t_entry a[MAX_FSO_IN_DIR], int start, int count)
{
	int i;
	
	i = -1;
	while (++i < count)
	{
		a[i] = a[start + i];
	}
	
}

int		delete_files(t_entry a[MAX_FSO_IN_DIR], int count)
{
	int	i;
	int	j;
	
	i = -1;
	j = -1;
	while (++i < count)
	{
		if (is_folder(a[i].s.st_mode))
		{
			++j;
			if (i > j)
			{
				if (!is_null_entry(a[j]) && is_folder(a[j].s.st_mode))
				{
					ft_putstr("wrong");
					exit(100500);
				}
				a[j] = a[i];
				a[i] = create_null_entry();
			}
			continue;
		}
	}
	return (j);
}

int			copy_array(t_entry dst[], t_entry src[], int count)
{
	int i;
	
	i = -1;
	while (++i < count)
	{
		dst[i] = src[i];
	}
	return (count);
}

/*
void		print_folder_recursive(t_entry folder, t_input input)
{
	size_t	printed_count = 0;
#define BUF_SIZE 100000//MAX_FSO_IN_DIR * 6
	//t_entry	not_processed[BUF_SIZE];
	t_entry	*not_processed = malloc(sizeof(t_entry) * BUF_SIZE);
	int		remain = 0;
	//t_entry	folder_entries[MAX_FSO_IN_DIR];
	t_entry	*folder_entries = NULL;
	int folder_entries_count = get_folder_entries(&folder_entries, folder, input.find_options);
	print_folder_entries(folder_entries, folder_entries_count, input);
	printed_count += folder_entries_count;
	remain = copy_array(not_processed, folder_entries, folder_entries_count);
	free(folder_entries);
	folder_entries = NULL;
	for (int i = 0; i < remain; i++)
	{
		t_entry e = not_processed[i];
		if (is_folder(e.s.st_mode) && !is_cur_dir(e.full_name.name) && !is_parent_dir(e.full_name.name))
		{
			ft_putstr("\n");
			ft_putstr(e.full_name.path);
			//printf(" (%zu)", printed_count);
			ft_putstr(":\n");
			//print_folder_recursive(e, input);
			folder_entries_count = get_folder_entries(&folder_entries, e, input.find_options);
			print_folder_entries(folder_entries, folder_entries_count, input);
			printed_count += folder_entries_count;
			if (remain + folder_entries_count >= BUF_SIZE)
			{
				remain -= i;
				move_array(not_processed, i, remain);
				i = 0;
				remain = delete_files(not_processed, remain);
				if (remain + folder_entries_count >= BUF_SIZE)
				{
					ft_putstr("not enough space\n");
					//printf("total entries printed:\t%zu\n", printed_count);
					free(not_processed);
					exit(49);
				}
			}
			remain += copy_array(not_processed + remain, folder_entries, folder_entries_count);
			free(folder_entries);
			folder_entries = NULL;
		}
	}
	free(not_processed);
}
*/
void		print_folder_recursive(t_entry folder, t_input input)
{
	//t_entry	entries[MAX_FSO_IN_DIR];
	//int count = get_folder_entries(entries, folder, input.find_options);
	//print_folder_entries(entries, count, input);
	
	//size_t	printed_count = 0;
#define BUF_SIZE 100000//MAX_FSO_IN_DIR * 6
	t_entry	*folder_entries = NULL;
	int folder_entries_count = get_folder_entries(&folder_entries, folder, input.find_options);
	print_folder_entries(folder_entries, folder_entries_count, input);
	//printed_count += folder_entries_count;
	//remain = copy_array(not_processed, folder_entries, folder_entries_count);
	for (int i = 0; i < folder_entries_count; i++)
	{
		t_entry e = folder_entries[i];
		if (is_folder(e.s.st_mode) && !is_cur_dir(e.full_name.name) && !is_parent_dir(e.full_name.name))
		{
			ft_putstr("\n");
			ft_putstr(e.full_name.path);
			ft_putstr(":\n");
			print_folder_recursive(e, input);
		}
	}
	free(folder_entries);
	folder_entries = NULL;
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
		if (input.args_count > 1)
		{
			ft_putstr(folders[i].full_name.path);
			ft_putstr(":\n");
		}
		if (input.find_options.recursive)
		{
			print_folder_recursive(folders[i], input);
		}
		else
		{
			t_entry*	entries;
			int entries_count = get_folder_entries(&entries, folders[i], input.find_options);
			//log_log("entries found in ");
			//log_line(folders[i].full_name.path);
			//log_entries(entries, entries_count);
			print_folder_entries(entries, entries_count, input);
			free(entries);
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
	t_input input = parse_arguments(argc - 1, argv + 1);
	log_input(input);
	print_entries(sort(input.files, input.files_count, input.sort_options), input.files_count, input.print_options);

	print_folders(sort(input.folders, input.folders_count, input.sort_options), input.folders_count, input);
	return (0);
}
