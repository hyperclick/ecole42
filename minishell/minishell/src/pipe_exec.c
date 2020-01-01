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
	debug_printf("close_g_fd_to_close");
	close_fd(g_fd_to_close);
	g_fd_to_close = -2;
}

pid_t	pe2(char *cmd, int r, int w)
{
	pid_t pid;

	debug_printf("exec %d > %s > %d\n", r, cmd, w);
	restore_stdin();
	restore_stdout();
	redirect(r, STDIN_FILENO);
	redirect(w, STDOUT_FILENO);
	pid = (exec(cmd));
	if (w != STDOUT_FILENO)
	{
		close_fd(w);
	}
	return (pid);
}

pid_t	pipe_exec2(t_list *p, int prev_r)
{
	int	r;
	int	w;

	if (p->next == NULL)
	{
		return (pe2(ft_strdup((char*)p->content), prev_r, STDOUT_FILENO));
	}
	ft_pipe(&r, &w);
	g_fd_to_close = r;
	pe2(ft_strdup((char*)p->content), prev_r, w);
	return (pipe_exec2(p->next, r));
}

void	pipe_exec(char *str)
{
	pid_t	pid;
	t_list	*p;

	p = pipe_parse(str);
	debug_set_pname(str);
	pid = pipe_exec2(p, STDIN_FILENO);
	debug_printf("pipe_exec2 returned: %d\n", pid);
	pipe_free(&p);
	if (pid > 0)
	{
		debug_printf("waiting %s to finish\n", str);
		set_awaited_process(pid);
		wait_child(pid);
		debug_printf("%s finished\n", str);
		set_awaited_process(0);
	}
	free(str);
}
