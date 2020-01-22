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

BOOL	is_del_or_backspace(char *str)
{
	return (ft_strequ(KEY_DELETE, str)
		|| (ft_strlen(str) == 1 && *str == KEY_BACKSPACE));
}

int		process_del_or_backspace(char *cmd_name)
{
	ft_strcpy(cmd_name, "KEY_DEL");
	process_delete();
	if (g_options_count == 0)
	{
		return (3);
	}
	return (DO_NOT_EXIT);
}

int		process_char(char *cmd_name)
{
	if (*cmd_name == KEY_ESC)
	{
		ft_strcpy(cmd_name, "KEY_ESC");
		return (1);
	}
	else if (*cmd_name == '\n')
	{
		ft_strcpy(cmd_name, "KEY_ENTER");
		show_selection();
		return (0);
	}
	else if (*cmd_name == ' ')
	{
		ft_strcpy(cmd_name, "KEY_SPACE");
		toggle_active_cell(g_table); 
		process_key_right();
		return (DO_NOT_EXIT);
	}
	else if (*cmd_name == KEY_BACKSPACE)
	{
		return (process_del_or_backspace(cmd_name));
	}
	return (DO_NOT_REDRAW);
}

int		process_others(char *cmd_name)
{
	if (ft_strequ(KEY_UP, cmd_name))
	{
		ft_strcpy(cmd_name, "KEY_UP");
		process_key_up();
		return (DO_NOT_EXIT);
	}
	else if (ft_strequ(KEY_DOWN, cmd_name))
	{
		ft_strcpy(cmd_name, "KEY_DOWN");
		process_key_down();
		return (DO_NOT_EXIT);
	}
	else if (ft_strequ(KEY_LEFT, cmd_name))
	{
		ft_strcpy(cmd_name, "KEY_LEFT");
		process_key_left();
		return (DO_NOT_EXIT);
	}
	else if (ft_strequ(KEY_RIGHT, cmd_name))
	{
		ft_strcpy(cmd_name, "KEY_RIGHT");
		process_key_right();
		return (DO_NOT_EXIT);
	}
	return (DO_NOT_REDRAW);
}

int		process_command2(char *cmd_name)
{
	if (ft_strlen(cmd_name) == 1)
	{
		return (process_char(cmd_name));
	}
	if (is_del_or_backspace(cmd_name))
	{
		return (process_del_or_backspace(cmd_name));
	}
	return (process_others(cmd_name));
}
