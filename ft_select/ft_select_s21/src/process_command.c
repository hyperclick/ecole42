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

int			process_command2(char* cmd_name)
{
	if (ft_strlen(cmd_name) == 1)
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
			return (-20);
		}
	}
	if (is_del_or_backspace(cmd_name))
	{
		ft_strcpy(cmd_name, "KEY_DEL");
		process_delete();
		if (g_options_count == 0)
		{
			return (3);
		}
		return (-20);
	}
	else if (ft_strequ(KEY_UP, cmd_name))
	{
		ft_strcpy(cmd_name, "KEY_UP");
		process_key_up();
		return (-20);
	}
	else if (ft_strequ(KEY_DOWN, cmd_name))
	{
		ft_strcpy(cmd_name, "KEY_DOWN");
		process_key_down();
		return (-20);
	}
	else if (ft_strequ(KEY_LEFT, cmd_name))
	{
		ft_strcpy(cmd_name, "KEY_LEFT");
		process_key_left();
		return (-20);
	}
	else if (ft_strequ(KEY_RIGHT, cmd_name))
	{
		ft_strcpy(cmd_name, "KEY_RIGHT");
		process_key_right();
		return (-20);
	}

	return (-21);
}

BOOL			process_command(char *str)
{
	char cmd_name[100];
	int		r;

	if (str == NULL)
	{
		ft_exit(5);
	}
	ft_strcpy(cmd_name,str);
	free(str);
	debug_printf("\n");
	debug_printf("-----------------------\n");
	debug_printf("process command: '%s'\n", cmd_name);
	r = process_command2(cmd_name);
	debug_printf("command processed: '%s'\n", cmd_name);
	debug_printf("-------------------------\n");
	debug_printf("\n");
	if (r == -21)
	{
		return (FALSE);
	}
	if (r!=-20)
	{
		ft_exit(r);
	}
	return (TRUE);
}