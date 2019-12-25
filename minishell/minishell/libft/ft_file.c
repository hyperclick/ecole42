/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:17:30 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:17:32 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	g_stdin = -1;
int g_stdout = -1;
void save_stdin()
{
	g_stdin = dup(STDIN_FILENO);
	debug_printf("duplicated stdin to %d\n", g_stdin);
}
void	restore_stdin()
{
	//close_fd(STDIN_FILENO);
	redirect(g_stdin, STDIN_FILENO);
}
void	restore_stdout()
{
	redirect(g_stdin, STDOUT_FILENO);
}
void save_stdout()
{
	g_stdout = dup(STDOUT_FILENO);
	debug_printf("duplicated stdout to %d\n", g_stdout);
}


void		close_fd(int fd)
{
	debug_printf("close(%d)\n", fd);
	close(fd);
}
void redirect(int a, int b)
{
	dup2(a, b);
	debug_printf("redirect: %d->%d\n", b, a);
	//printf("redirected: %d->%d\n", b, a);
}