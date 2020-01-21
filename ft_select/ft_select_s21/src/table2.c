/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:29:04 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:29:06 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	get_offset(t_table *t, int row, int col)
{
	return (row * t->width + col);
}

BOOL		is_out_of_table2(t_table *t, int offset)
{
	return (offset > t->cells_count - 1);
}

BOOL		is_out_of_table(t_table *t, int row, int col)
{
	return (row < 0 || col < 0 || is_out_of_table2(t, get_offset(t, row, col)));
}

char *get_cell(t_table *t, int row, int col)
{
	int offset;

	offset = get_offset(t, row, col);
	if (is_out_of_table2(t, offset))
	{
		return (NULL);
	}
	if (t->cells[offset] == NULL)
	{
		debug_printf("smth wrong\n");
		ft_exit(11);
	}
	return (t->cells[offset]);
}

BOOL		is_empty(const char *cell)
{
	return cell == NULL;
}