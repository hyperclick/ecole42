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

void		zta_remove_at(void **a, int size, int n)
{
		debug_printf("free '%s'\n", a[n]);
		free(a[n]);
	while (n < size)
	{
		a[n] = a[n + 1];
		n++;
	}
	//a[ size - 1] = NULL;
}

BOOL	process_delete(void)
{
	zta_remove_at((void**)g_options, g_options_count,  get_active_cell_offset());
	g_options_count--;
	if (get_active_cell_offset() == g_options_count)
	{
		set_active_cell_offset(g_options_count - 1);
	}
	debug_printf("after remove at %d:\n", get_active_cell_offset());
	debug_print_zt_array((const char**)g_options);
	return (TRUE);
}
