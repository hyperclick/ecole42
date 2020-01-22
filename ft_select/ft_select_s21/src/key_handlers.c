/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 12:30:12 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 12:30:15 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "key_constants.h"

BOOL	process_key_down(void)
{
	t_coord	c;
	int		new_row;

	if (g_table->height == 1)
	{
		return (TRUE);
	}
	c = get_active_cell_coord(g_table);
	new_row = c.row == get_last_row_in_col(g_table, c.col) ? 0 : c.row + 1;
	c.row = new_row;
	set_active_cell(g_table, c);
	return (TRUE);
}

BOOL	process_key_up(void)
{
	t_coord c;
	int		new_row;

	if (g_table->height == 1)
	{
		return (TRUE);
	}
	c = get_active_cell_coord(g_table);
	new_row = c.row == 0 ? get_last_row_in_col(g_table, c.col) : c.row - 1;
	c.row = new_row;
	set_active_cell(g_table, c);
	return (TRUE);
}

BOOL	process_key_left(void)
{
	if (g_table->width == 1)
	{
		return (TRUE);
	}
	if (get_active_cell_offset() == 0)
	{
		set_active_cell_offset(g_options_count - 1);
		return (TRUE);
	}
	set_active_cell_offset(get_active_cell_offset() - 1);
	return (TRUE);
}

BOOL	process_key_right(void)
{
	if (g_table->width == 1)
	{
		return (TRUE);
	}
	if (get_active_cell_offset() == g_options_count - 1)
	{
		set_active_cell_offset(0);
		return (TRUE);
	}
	set_active_cell_offset(get_active_cell_offset() + 1);
	return (TRUE);
}

BOOL	process_delete(void)
{
	int	offset;

	offset = get_active_cell_offset();
	zta_remove_at((void **)g_options, g_options_count, offset);
	g_options_count--;
	if (offset == g_options_count)
	{
		set_active_cell_offset(g_options_count - 1);
	}
	handle_item_deleted(offset);
	rebuild_table();
	return (TRUE);
}
