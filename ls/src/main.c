/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:48:58 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:48:59 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

BOOL	is_cur_dir(const char name[])
{
	return (ft_strcmp(name, ".") == 0);
}

BOOL	is_parent_dir(const char name[])
{
	return (ft_strcmp(name, "..") == 0);
}

int		calc_total(t_entry entries[], int count)
{
	int	total;
	int	i;

	total = 0;
	i = -1;
	while (++i < count)
	{
		total += entries[i].s.st_blocks;
	}
	return (total);
}

void	print_folder_entries(t_entry entries[], int count, t_input input)
{
	sort(entries, count, input.sort_options);
	if (input.print_options.details && count != 0)
	{
		ft_putstr("total ");
		ft_putnbr(calc_total(entries, count));
		ft_putstr("\n");
	}
	print_entries(entries, count, input.print_options);
}

void		print_folder_recursive(t_entry folder, t_input input)
{
#define BUF_SIZE 100000
	t_entry	*folder_entries;
	int		folder_entries_count;
	t_entry	e;
	

	folder_entries = NULL;
	folder_entries_count = get_folder_entries(&folder_entries, folder, input.find_options);
	print_folder_entries(folder_entries, folder_entries_count, input);
	for (int i = 0; i < folder_entries_count; i++)
	{
		e = folder_entries[i];
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
	log_line(argv[0]);
	t_input input = parse_arguments(argc - 1, argv + 1);
	log_input(input);
	print_entries(sort(input.files, input.files_count, input.sort_options), input.files_count, input.print_options);

	print_folders(sort(input.folders, input.folders_count, input.sort_options), input.folders_count, input);
	return (0);
}
