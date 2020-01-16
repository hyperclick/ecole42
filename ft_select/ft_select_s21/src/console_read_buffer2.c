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

void		buffer_print(void)
{
	debug_printf("print buffer\n");
	dump_buffer();
	ft_putstr(get_buffer());
	move_cursor_left(get_printed_buf_len());
	move_cursor_right(get_act_x());
}

void		buffer_delete(void)
{
	if (get_g_x() < get_buf_len())
	{
		ft_str_remove_at((char*)get_buffer(), get_g_x());
		decrease_buffer();
	}
	else
	{
		debug_printf("!!!delete: get_g_x() >= get_buf_len()\n");
	}
}

void		buffer_backspace(void)
{
	if (get_g_x() > 0)
	{
		dec_cursor_pos();
		ft_str_remove_at((char*)get_buffer(), get_g_x());
		decrease_buffer();
	}
	else
	{
		debug_printf("!!!backspace: get_g_x() <= 0\n");
	}
}

void		buffer_insert(char c)
{
	increase_buffer();
	ft_str_insert_at((char*)get_buffer(), get_g_x(), c);
	inc_cursor_pos();
}
