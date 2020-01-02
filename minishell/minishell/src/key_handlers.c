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

static void	dump_control(char control[10])
{
	int i;

	i = -1;
	while (++i < 4)
	{
		debug_printf("\n%d ('%c')\n", control[i], control[i]);
	}
}

static BOOL	process_chord(char control[10])
{
	if (ft_strequ(control, KEY_LEFT))
	{
		return (process_key_left());
	}
	if (ft_strequ(control, KEY_RIGHT))
	{
		return (process_key_right());
	}
	if (ft_strequ(control, KEY_UP))
	{
		return (process_key_up());
	}
	if (ft_strequ(control, KEY_DOWN))
	{
		return (process_key_down());
	}
	if (ft_strequ(control, KEY_DELETE))
	{
		return (process_delete());
	}
	return (FALSE);
}

static BOOL	processed(char control[10])
{
	if (ft_strlen(control) > 4)
	{
		debug_printf("unknown input\n");
		dump_control(control);
		return (TRUE);
	}
	if (process_chord(control))
	{
		return (TRUE);
	}
	if (control[0] == KEY_BACKSPACE)
	{
		return (process_backspace());
	}
	if (control[0] == KEY_TAB)
	{
		return (process_tab());
	}
	return (FALSE);
}

void		process_not_printable(char control[10], int c)
{
	ft_str_append(control, c);
	if (processed(control))
	{
		control[0] = 0;
	}
}
