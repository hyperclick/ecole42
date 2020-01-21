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

static struct termios	g_stored_settings;
struct termios			g_new_settings;
static BOOL				g_set = FALSE;

void		enter_full_screen()
{
	tputs(tgetstr("ti", NULL), 1, ft_putc_err);
}

void		exit_full_screen()
{
	tputs(tgetstr("te", NULL), 1, ft_putc_err);
}

void		validate_terminal()
{
	char		buf[1000];
	int		r;
	char		*t;

	if (!isatty(STDERR_FILENO))
	{
		ft_putendl_fd("stderr not a terminal. rerun without redirect\n", STDERR_FILENO);
		ft_exit(5);
	}
	t = getenv("TERM");
	if (t == NULL)
	{
		ft_printf_fd(STDERR_FILENO, "$TERM is not set\n");
		ft_exit(4);
	}
	r = tgetent(buf, t);
	if (r <= 0)
	{
		ft_printf_fd(STDERR_FILENO, "terminal '%s' not found in termios database\n", t);
		ft_exit(5);
	}
}

void	set_keypress(void)
{
	validate_terminal();
	tcgetattr(STDERR_FILENO, &g_stored_settings);
	g_set = TRUE;
	tcgetattr(STDERR_FILENO, &g_new_settings);
	g_new_settings.c_lflag &= ~(ICANON | ECHO);
	g_new_settings.c_cc[VMIN] = 1;
	g_new_settings.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSANOW, &g_new_settings);
	enter_full_screen();
	hide_cursor();
}

void	reset_keypress(void)
{
	if (g_set)
	{
		debug_printf("restore term caps\n");
		tcsetattr(STDERR_FILENO, TCSANOW, &g_stored_settings);
		show_cursor();
		exit_full_screen();
		g_set = FALSE;
	}
	else
	{
		debug_printf("g_stored_settings = NULL\n");
	}
}