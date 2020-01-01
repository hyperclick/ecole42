/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:17:30 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:17:32 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

pid_t		ft_fork(void)
{
	pid_t	pid;
	
	debug_printf("fork\n");
	pid = fork();
	if (pid == -1)
	{
		ft_e_putstr("can't fork, error occured\n");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

BOOL		is_child(pid_t pid)
{
	return (pid == 0);
}

static void	log_pipe(int r, int w)
{
	debug_printf("new pipe: r=%d, w=%d\n", r, w);
}

void		ft_pipe(int *r, int *w)
{
	int fd[2];
	
	if (pipe(fd) != 0)
	{
		ft_e_putstr("pipe() failed\n");
		debug_printf("pipe() failed\n");
		exit(1);
	}
	*r = fd[0];
	*w = fd[1];
	log_pipe(*r, *w);
}
