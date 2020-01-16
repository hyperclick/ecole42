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
#include "key_constants.h"

void	move_cursor_left(int x)
{
	debug_printf("<-(%d)\n", x);
	while (x-- > 0)
	{
		ft_putstr(KEY_LEFT);
	}
}

void	move_cursor_right(int x)
{
	debug_printf("->(%d)\n", x);
	while (x-- > 0)
	{
		ft_putstr(KEY_RIGHT);
	}
}

void	move_cursor_up(int x)
{
	debug_printf("^(%d)\n", x);
	while (x-- > 0)
	{
		ft_putstr(KEY_UP);
	}
}

void	move_cursor_down(int x)
{
	debug_printf("v(%d)\n", x);
	while (x-- > 0)
	{
		ft_putstr(KEY_DOWN);
	}
}

void	move_to_bol(void)
{
	move_cursor_left(get_act_x());
}
