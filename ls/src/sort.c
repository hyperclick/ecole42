/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:50:24 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:50:26 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	swap(t_entry entries[], int i, int j)
{
	t_entry	tmp;

	tmp = entries[i];
	entries[i] = entries[j];
	entries[j] = tmp;
}

static BOOL	need_swap(t_entry a, t_entry b, t_sort_options o)
{
	BOOL	second_is_greater;

	if (o.sort_by == SORT_BY_MOD_TIME)
	{
		second_is_greater = b.s.st_mtime < a.s.st_mtime;
		if (b.s.st_mtime == a.s.st_mtime)
		{
			second_is_greater =
				(ft_strcmp(b.full_name.name, a.full_name.name) >= 0);
		}
	}
	else if (o.sort_by == SORT_BY_NAME)
	{
		second_is_greater =
			(ft_strcmp(b.full_name.path, a.full_name.path) >= 0);
	}
	else
	{
		ft_putstr_fd("unknown sort", STDERR_FILENO);
		exit(1);
	}
	return (o.sort_desc == TRUE ? second_is_greater : !second_is_greater);
}

t_entry		*sort(t_entry entries[], int count, t_sort_options o)
{
	int		i;
	BOOL	not_sorted;

	not_sorted = TRUE;
	while (not_sorted)
	{
		not_sorted = FALSE;
		i = -1;
		while (++i < count - 1)
		{
			if (need_swap(entries[i], entries[i + 1], o))
			{
				swap(entries, i, i + 1);
				not_sorted = TRUE;
			}
		}
	}
	return (entries);
}
