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

char	get_previous_char(void)
{
	return (get_buffer()[get_g_x() - 1]);
}

char	get_next_char(void)
{
	return (get_buffer()[get_g_x() + 1]);
}

char	get_char_at_cursor(void)
{
	return (get_buffer()[get_g_x()]);
}

void	dump_buffer(void)
{
	debug_printf("vg_x: %d, agx: %d, \
				buf_len = %d, g_buffer = '%s', printed = %d\n"
				, get_g_x(), get_act_x(), get_buf_len(), get_buffer()
				, get_printed_buf_len());
}
