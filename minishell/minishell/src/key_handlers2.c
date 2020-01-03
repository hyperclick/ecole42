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

#include "minishell.h"
#include "key_constants.h"

char	get_previous_char()
{
	return (get_buffer()[get_g_x() - 1]);
}

char	get_next_char()
{
	return (get_buffer()[get_g_x() + 1]);
}
char	get_charat_cursor()
{
	return (get_buffer()[get_g_x()]);
}

BOOL	process_key_left(void)
{
	if (get_g_x() > 0)
	{
		move_cursor_left(get_previous_char() == '\t' ? TAB_LEN + 1 : 1);
		dec_cursor_pos();
	}
	return (TRUE);
}

BOOL	process_key_right(void)
{
	if (get_g_x() < get_buf_len())
	{
		move_cursor_right(get_charat_cursor() == '\t' ? TAB_LEN + 1 : 1);
		inc_cursor_pos();
	}
	return (TRUE);
}

BOOL	process_key_down(void)
{
	if (h_has_next())
	{
		buffer_set(h_get_next());
		buffer_print();
	}
	return (TRUE);
}

BOOL	process_key_up(void)
{
	if (h_has_previous())
	{
		buffer_set(h_get_previous());
		buffer_print();
	}
	return (TRUE);
}
BOOL	process_delete(void)
{
	clean_printed_text_and_move_cursor_left();
	buffer_delete();
	buffer_print();
	return (TRUE);
}

void	process_printable(char c)
{
	debug_printf("process printable: '%c'\n", c);
	clean_printed_text_and_move_cursor_left();
	buffer_insert(c);
	buffer_print();
}

BOOL	process_tab(void)
{
	return (TRUE);
}

BOOL	process_backspace(void)
{
	//	reset_keypress();
	//	cc_t cmd = get_param(VSTART);
	//	debug_printf("printing '%c' (%d)\n", cmd);
	//	//ft_putstr(KEY_CTRL_Q);
	//	ft_putchar(cmd);
	//	set_keypress();
	clean_printed_text_and_move_cursor_left();
	buffer_backspace();
	buffer_print();
	return (TRUE);
}
