/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_cell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:29:04 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:29:06 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		g_active_index = -1;

int		get_active_cell_offset()
{
	return (g_active_index);
}

void		set_active_cell_offset(int offset)
{
	g_active_index = offset;
}

void		set_active_cell(t_table *t, t_coord new_c)
{
	t_coord c;

	if (is_out_of_table(t, new_c.row, new_c.col))
	{
		debug_printf("ignore set active cell to %d:%d since it out of table\n", new_c.row, new_c.col);
		return;
	}
	c = get_active_cell_coord(t);
	set_active_cell_offset(get_offset(t, new_c.row, new_c.col));
	debug_printf("change active cell from %d:%d to %d:%d (%d)\n", c.row, c.col, new_c.row, new_c.col, g_active_index);
}

BOOL		is_active2(int offset)
{
	return (g_active_index == offset);
}

BOOL		is_active(t_table *t, int i, int j)
{
	return (is_active2(get_offset(t, i, j)));
}

