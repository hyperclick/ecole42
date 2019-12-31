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

void	move_cursor_left(int x)
{
	while (x-- > 0)
	{
		ft_putstr(KEY_LEFT);
		debug_printf("<\n");
	}
}

void	move_cursor_right(int x)
{
	while (x-- > 0)
	{
		ft_putstr(KEY_RIGHT);
	}
}

void	backspace(int x)
{
	int i;

	i = -1;
	while (++i < x)
	{
		ft_putstr(KEY_LEFT);
	}
	i = -1;
	while (++i < x)
	{
		ft_putstr(" ");
	}
	i = -1;
	while (++i < x)
	{
		ft_putstr(KEY_LEFT);
	}
}

BOOL	process_key_left(void)
{
	if (get_g_x() > 0)
	{
		move_cursor_left(1);
		dec_cursor_pos();
	}
	return (TRUE);
}

BOOL	process_key_right(void)
{
	if (get_g_x() < get_buf_len())
	{
		move_cursor_right(1);
		inc_cursor_pos();
	}
	return (TRUE);
}
