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
struct termios g_new_settings;
static BOOL				g_set = FALSE;


int	ft_putc(int c)
{
	ft_putchar(c);
	return (1);
}

void		enter_full_screen()
{
	tputs(tgetstr("ti", NULL), 1, ft_putc);
}

void		exit_full_screen()
{
	tputs(tgetstr("te", NULL), 1, ft_putc);
}

void		hide_cursor()
{
	tputs(tgetstr("vi", NULL), 1, ft_putc);
}

void		show_cursor()
{
	tputs(tgetstr("ve", NULL), 1, ft_putc);
}

void	set_keypress(void)
{
	char buf[1000];
	tgetent(buf, getenv("TERM")); 
	tcgetattr(STDERR_FILENO, &g_stored_settings);
	g_set = TRUE;
	tcgetattr(STDERR_FILENO, &g_new_settings);
	g_new_settings.c_lflag &= ~(ICANON | ECHO);
	g_new_settings.c_cc[VMIN] = 1;
	g_new_settings.c_cc[VTIME] = 4;
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

cc_t	get_param(int p)
{
	return (g_new_settings.c_cc[p]);
}

void		clear()
{
	tputs(tgetstr("cl", NULL), 1, ft_putc);
}
