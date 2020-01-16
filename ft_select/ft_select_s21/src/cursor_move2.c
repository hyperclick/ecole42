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

static int				g_virtual_x;
static int				g_actual_x;

int		get_g_x(void)
{
	return (g_virtual_x);
}

int		get_act_x(void)
{
	return (g_actual_x);
}

void	buffer_changed(void)
{
	g_actual_x = get_printed_buf_len();
	g_virtual_x = get_buf_len();
}

void	inc_cursor_pos(void)
{
	if (g_virtual_x > get_buf_len())
	{
		ft_e_putstr("inc_cursor_pos: vg_x >= g_buf_len");
		reset_keypress();
		exit(1);
	}
	g_actual_x += (get_buffer()[g_virtual_x] == '\t') ? TAB_LEN : 1;
	++g_virtual_x;
	debug_printf("vgx = %d, agx = %d\n", g_virtual_x, g_actual_x);
}

void	dec_cursor_pos(void)
{
	if (g_virtual_x < 1)
	{
		ft_e_putstr("process_key_left: g_x <= 1");
		reset_keypress();
		exit(1);
	}
	--g_virtual_x;
	g_actual_x -= (get_buffer()[g_virtual_x] == '\t') ? TAB_LEN : 1;
	debug_printf("vgx = %d, agx = %d\n", g_virtual_x, g_actual_x);
}
