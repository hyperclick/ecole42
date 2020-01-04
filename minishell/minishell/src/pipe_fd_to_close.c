/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:25:50 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:25:52 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_fd_to_close = -11;

void	close_g_fd_to_close(void)
{
	debug_printf("close_g_fd_to_close: %d\n", g_fd_to_close);
	if (g_fd_to_close == -11)
	{
		return ;
	}
	close_fd(g_fd_to_close);
	g_fd_to_close = -2;
}

void	pipe_set_fd_to_close(int fd)
{
	debug_printf("pipe_set_fd_to_close(%d)\n", fd);
	if (fd <= 3)
	{
		ft_exit(4);
	}
	g_fd_to_close = fd;
}
