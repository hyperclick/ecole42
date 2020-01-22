/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:29:04 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:29:06 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_last_row(t_table *t)
{
	return (t->height - 1);
}

int		get_last_col(t_table *t)
{
	return (t->width - 1);
}

t_coord	get_last_cell_coord(t_table *t)
{
	return (get_coord_by_offset(t, t->cells_count - 1));
}

int		get_last_row_in_col(t_table *t, int col)
{
	t_coord last;

	last = get_last_cell_coord(t);
	return (col <= last.col ? last.row : last.row - 1);
}

int		get_last_col_in_row(t_table *t, int row)
{
	t_coord last;

	last = get_last_cell_coord(t);
	debug_printf("last cell coord = %d:%d\n", last.row, last.col);
	return (row < last.row ? get_last_col(t) : last.col);
}
