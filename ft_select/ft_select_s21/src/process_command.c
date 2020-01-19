/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 12:24:18 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 12:24:25 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

BOOL		is_del_or_backspace(char *str)
{
	return (ft_strequ(KEY_DELETE, str)
		|| (ft_strlen(str) == 1 && *str == KEY_BACKSPACE));
}

void			process_command(char *str)
{
	int		r;

	r = 20;
	if (str == NULL)
	{
		ft_exit(r);
	}
	debug_printf("\n");
	debug_printf("-----------------------\n");
	debug_printf("process command: '%s'\n", str);
	if (ft_strlen(str) == 1)
	{
		if (*str == KEY_ESC)
		{
			r = 1;
		}
		if (*str == '\n')
		{
			r = 0;
			show_selection();
		}
		if (*str == ' ')
		{
			toggle_active_cell(g_table);
		}
	}
	if (is_del_or_backspace(str))
	{
		process_delete();
		if (g_options_count == 0)
		{
			r = 1;
		}
	}
	if (ft_strequ(KEY_UP, str))
	{
		process_key_up();
	}
	if (ft_strequ(KEY_DOWN, str))
	{
		process_key_down();
	}
	if (ft_strequ(KEY_LEFT, str))
	{
		process_key_left();
	}
	if (ft_strequ(KEY_RIGHT, str))
	{
		process_key_right();
	}
	debug_printf("command processed: '%s'\n", str);
	debug_printf("-------------------------\n");
	debug_printf("\n");
			free(str);
	if (r!=20)
	{
		ft_exit(r);
	}
}