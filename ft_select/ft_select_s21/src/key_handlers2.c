/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 12:30:12 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 12:30:15 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

BOOL	process_delete(void)
{
	int	offset;

	offset = get_active_cell_offset();
	zta_remove_at((void**)g_options, g_options_count,  offset);
	g_options_count--;
	if (offset == g_options_count)
	{
		set_active_cell_offset(g_options_count - 1);
	}
	//debug_printf("after remove at %d:\n", offset);
	//debug_print_zt_array((const char**)g_options);
	handle_item_deleted(offset);
	rebuild_table();
	return (TRUE);
}
