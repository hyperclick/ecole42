/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_folders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:48:58 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:48:59 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int			calc_total(t_entry entries[], int count)
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

void		print_folder_entries(t_entry entries[], int count, t_input input)
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
	t_entry	*folder_entries;
	int		folder_entries_count;
	t_entry	e;
	int		i;

	folder_entries = NULL;
	folder_entries_count = get_folder_entries(
							&folder_entries, folder, input.find_options);
	print_folder_entries(folder_entries, folder_entries_count, input);
	i = -1;
	while (++i < folder_entries_count)
	{
		e = folder_entries[i];
		if (is_folder(e.s.st_mode)
			&& !is_cur_dir(e.full_name.name)
			&& !is_parent_dir(e.full_name.name))
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

static void	print_folder(t_entry folder, const t_input input)
{
	t_entry		*entries;
	int			entries_count;

	entries_count = get_folder_entries(&entries, folder, input.find_options);
	print_folder_entries(entries, entries_count, input);
	free(entries);
}

void		print_folders(t_entry folders[], int count, t_input input)
{
	int	i;

	i = -1;
	while (++i < count)
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
			print_folder(folders[i], input);
		}
	}
}
