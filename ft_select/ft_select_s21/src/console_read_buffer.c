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

static int				g_buf_len;
static char				g_buffer[PATH_MAX];

int			get_buf_len(void)
{
	return (g_buf_len);
}

void		set_buf_len(int len)
{
	g_buf_len = len;
}

const char	*get_buffer(void)
{
	return (g_buffer);
}

void		increase_buffer(void)
{
	if (g_buf_len++ > PATH_MAX - 1)
	{
		ft_e_putstr("buffer is too small\n");
		debug_printf("buffer is too small\n");
		reset_keypress();
		exit(1);
	}
	g_buffer[g_buf_len] = 0;
}

void		decrease_buffer(void)
{
	if (--g_buf_len < 0)
	{
		ft_e_putstr("buffer is negative\n");
		debug_printf("buffer is negative\n");
		reset_keypress();
		exit(1);
	}
	g_buffer[g_buf_len] = 0;
}
