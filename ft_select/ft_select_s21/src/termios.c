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
#include <ctype.h>

static struct termios	stored_settings;
static BOOL				g_set = FALSE;


int	ft_putc(int c)
{
	ft_putchar(c);
	return (1);
}

void	set_keypress(void)
{
	struct termios new_settings;

	tcgetattr(STDIN_FILENO, &stored_settings);
	//debug_printf("eof = '%c' (%d)\n", stored_settings.c_cc[VEOF]);
	//debug_printf("set : VSTART = '%c' (%d)\n", stored_settings.c_cc[VSTART]);
	//debug_printf("set : VSTART = '%c' (%d)\n", get_param(VSTART));
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ICANON & ~ECHO);
	new_settings.c_cc[VTIME] = 1;
	new_settings.c_cc[VMIN] = 4;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
	g_set = TRUE;

	int		res;
	char* buf = NULL;
	char* term = getenv("TERM");
	res = tgetent(buf, term);
	free(buf);
	//free(term);
	(void)res;
	//ft_exit(1);
	buf = tgetstr("ti", NULL);
	tputs(buf, 1, ft_putc);
	//free(buf);
}

void	reset_keypress(void)
{
	if (g_set)
	{
		tputs(tgetstr("te", NULL), 1, ft_putc);
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


void		clear()
{

	tputs(tgetstr("cl", NULL), 1, ft_putc);
	//	tputs(tgetstr("ti", NULL), 1, ft_putc);
		//move_cursor_left(g_size_current.ws_col);
		//move_cursor_up(g_table->height - 1);
		//ft_printf("...........");
		//move_cursor_left(5);
}
