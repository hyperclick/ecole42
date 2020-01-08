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
		move_cursor_right(get_char_at_cursor() == '\t' ? TAB_LEN + 1 : 1);
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
