/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:57:20 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:57:22 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct winsize g_size_current;

void	update_hw(void)
{
	ioctl(STDERR_FILENO, TIOCGWINSZ, &g_size_current);
	debug_printf("lines %d\n", g_size_current.ws_row);
	debug_printf("columns %d\n", g_size_current.ws_col);
}

void	sig_winch_handler(void)
{
	update_hw();
	rebuild_table();
	redraw();
	hide_cursor();
}

void	sig_tstp_handler(void)
{
	reset_keypress();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

void	sig_cont_handler(void)
{
	set_keypress();
	set_signal_handlers();
	redraw();
}

void	exit_signal_handler(void)
{
	reset_keypress();
	ft_exit(2);
}
