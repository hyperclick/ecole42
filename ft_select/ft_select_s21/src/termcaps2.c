/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 12:30:12 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 12:30:15 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <ctype.h>

int	ft_putc_err(int c)
{
	ft_putchar_fd(c, STDERR_FILENO);
	return (1);
}

void		clear()
{
	tputs(tgetstr("cl", NULL), 1, ft_putc_err);
}

void		ft_tputs(const char *str)
{
	tputs(str, 1, ft_putc_err);
}

void		hide_cursor()
{
	tputs(tgetstr("vi", NULL), 1, ft_putc_err);
}

void		show_cursor()
{
	tputs(tgetstr("ve", NULL), 1, ft_putc_err);
}