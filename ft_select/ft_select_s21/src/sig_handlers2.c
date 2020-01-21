/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handlers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:57:20 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:57:22 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		sig_handler(int signum)
{
	debug_printf("\n");
	debug_printf("\n");
	debug_printf("-----------------------\n");
	debug_printf("signal %d\n", signum);
	if (signum == SIGWINCH)
	{
		sig_winch_handler();
	}
	if (signum == SIGTSTP)
	{
		sig_tstp_handler();
	}
	if (signum == SIGCONT)
	{
		sig_cont_handler();
	}
	if (signum == SIGABRT || signum == SIGINT || signum == SIGSTOP|| signum == SIGKILL|| signum == SIGQUIT )
	{
		exit_signal_handler();
	}
}

void		set_signal_handlers()
{
	signal(SIGWINCH, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGCONT, sig_handler);
	signal(SIGABRT, sig_handler);
	signal(SIGINT, sig_handler);
	signal(SIGSTOP, sig_handler);
	signal(SIGKILL, sig_handler);
	signal(SIGQUIT, sig_handler);
}
