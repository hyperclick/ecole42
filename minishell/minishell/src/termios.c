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
#include <ctype.h>

static struct termios	stored_settings;
static BOOL				g_set = FALSE;

void	set_keypress(void)
{
	struct termios new_settings;

	tcgetattr(STDIN_FILENO, &stored_settings);
	debug_printf("eof = '%c' (%d)\n", stored_settings.c_cc[VEOF]);
	debug_printf("set : VSTART = '%c' (%d)\n", stored_settings.c_cc[VSTART]);
	debug_printf("set : VSTART = '%c' (%d)\n", get_param(VSTART));
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ICANON & ~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
	g_set = TRUE;
	return ;
}

void	reset_keypress(void)
{
	if (g_set)
	{
		debug_printf("restore term caps\n");
		tcsetattr(STDIN_FILENO, TCSANOW, &stored_settings);
		g_set = FALSE;
	}
	else
	{
		debug_printf("g_set is not set\n");
	}
}

cc_t	get_param(int p)
{
	return (stored_settings.c_cc[p]);
}
