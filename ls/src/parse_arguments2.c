/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:48:40 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:48:42 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	remove_file(t_input *input, int n)
{
	input->files_count--;
	while (n < input->files_count)
	{
		input->files[n] = input->files[n + 1];
		n++;
	}
}

static void	process_link(int i, t_input *input, t_entry *t)
{
	t->full_name = input->files[i].full_name;
	parse_arguments_add_entry(input, *t);
	remove_file(input, i);
}

void		process_links(t_input *input)
{
	int			i;
	BOOL		link_found;
	t_entry		t;

	if (input->print_options.details)
		return ;
	link_found = TRUE;
	while (link_found)
	{
		link_found = FALSE;
		i = -1;
		while (++i < input->files_count)
		{
			if (is_link(input->files[i].s.st_mode))
			{
				t = try_get_target_entry(input->files[i].full_name.path);
				if (is_folder(t.s.st_mode))
				{
					process_link(i, input, &t);
					link_found = TRUE;
					break ;
				}
			}
		}
	}
}

static void	print_usage(const char f)
{
	ft_putstr_fd("ls: illegal option -- ", STDERR_FILENO);
	ft_putchar_fd(f, STDERR_FILENO);
	ft_putstr_fd(
		"\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n"
		, STDERR_FILENO);
}

BOOL		parse_flag(t_input *input, const char f)
{
	if (f == 'l')
	{
		input->print_options.single_column = FALSE;
		return (input->print_options.details = TRUE);
	}
	if (f == '1')
	{
		input->print_options.details = FALSE;
		return (input->print_options.single_column = TRUE);
	}
	if (f == 'a')
		return (input->find_options.all = TRUE);
	if (f == 'R')
		return (input->find_options.recursive = TRUE);
	if (f == 'r')
		return (input->sort_options.sort_desc = TRUE);
	if (f == 't')
	{
		input->sort_options.sort_by = SORT_BY_MOD_TIME;
		return (TRUE);
	}
	if (f == 'T')
		return (input->print_options.long_datetime = TRUE);
	print_usage(f);
	exit(1);
}
