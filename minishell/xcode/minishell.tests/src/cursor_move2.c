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

static int				g_x;

int		get_g_x(void)
{
	return (g_x);
}

void	set_g_x(int x)
{
	g_x = x;
}

void	inc_cursor_pos(void)
{
	if (g_x > get_buf_len())
	{
		ft_e_putstr("inc_cursor_pos: g_x >= g_buf_len");
		reset_keypress();
		exit(1);
	}
	++g_x;
	debug_printf("gx = %d\n", g_x);
}

void	dec_cursor_pos(void)
{
	if (g_x < 1)
	{
		ft_e_putstr("process_key_left: g_x <= 1");
		reset_keypress();
		exit(1);
	}
	--g_x;
	debug_printf("gx = %d\n", g_x);
}

void	move_to_bol(void)
{
	move_cursor_left(get_g_x());
}
