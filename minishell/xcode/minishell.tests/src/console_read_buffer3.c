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

void		clean_printed_text(void)
{
	int i;

	move_to_bol();
	i = -1;
	while (++i < get_buf_len())
	{
		ft_putchar(' ');
		debug_printf("_\n");
	}
}

void		clean_printed_text_and_move_cursor_left(void)
{
	debug_printf("g_x: %d, g_buf_len = %d, g_buffer = '%s'\n"
				, get_g_x(), get_buf_len(), get_buffer());
	clean_printed_text();
	move_cursor_left(get_buf_len());
}

void		clean_buffer(void)
{
	char	*buffer;

	buffer = (char*)get_buffer();
	set_buf_len(0);
	buffer[get_buf_len()] = 0;
	set_g_x(0);
}

void		buffer_set(const char *new_value)
{
	clean_printed_text_and_move_cursor_left();
	ft_strcpy((char*)get_buffer(), new_value);
	set_buf_len(ft_strlen(get_buffer()));
	set_g_x(get_buf_len());
}
