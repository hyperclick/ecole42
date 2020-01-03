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

int			get_printed_buf_len(void)
{
	return (get_buf_len() + ft_str_count_chars(get_buffer(), '\t') * (TAB_LEN - 1) );
}

void		clean_printed_text(void)
{
	int i;

	move_to_bol();
	debug_printf("_(%d)\n", get_printed_buf_len());
	i = -1;
	while (++i < get_printed_buf_len())
	{
		ft_putchar('_');
	}
}

void dump_buffer()
{
	debug_printf("vg_x: %d, agx: %d, g_buf_len = %d, g_buffer = '%s', printed = %d\n"
			, get_g_x(), get_act_x(), get_buf_len(), get_buffer(), get_printed_buf_len());
}

void		clean_printed_text_and_move_cursor_left(void)
{
	dump_buffer();
	clean_printed_text();
	move_cursor_left(get_printed_buf_len());
}

void		clean_buffer(void)
{
	char	*buffer;

	buffer = (char*)get_buffer();
	set_buf_len(0);
	buffer[get_buf_len()] = 0;
	buffer_changed();
}

void		buffer_set(const char *new_value)
{
	clean_printed_text_and_move_cursor_left();
	ft_strcpy((char*)get_buffer(), new_value);
	set_buf_len(ft_strlen(get_buffer()));
	buffer_changed();
}
