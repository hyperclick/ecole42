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
		return;
	}
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

BOOL	has_exit(const char  *str)
{
	char* trimmed;
	char* right;

	trimmed = ft_strtrim2(str, " \n\t");
	debug_printf("trimmed = '%s'\n", trimmed);
	if (ft_str_equals("exit", trimmed))
	{
		free(trimmed);
		return (TRUE);
	}
	if (!ft_str_starts_with(trimmed, "exit"))
	{
		free(trimmed);
		return(FALSE);
	}
	right = ft_strtrim2(trimmed + 4, " \n\t");
	debug_printf("trimmed = '%s', right = '%s'\n", trimmed, right);
	free(trimmed);
	if (*right == '>' || *right == '<')
	{
		free(right);
		return (TRUE);
	}
	free(right);
	return (FALSE);
}

BOOL	find_exit(t_list* p)
{
	while (p != NULL)
	{
		if (has_exit((const char*)p->content))
		{
			return (TRUE);
		}
		p = p->next;
	}
	return (FALSE);
}

void	pipe_exec(char *str)
{
	pid_t	pid;
	t_list	*p;

	p = pipe_parse(str);
	debug_set_pname(str);

	if (find_exit(p))
	{
		debug_printf("exit detected: %s\n", str);
		pipe_free(&p);
		free(str);
		ft_exit(0);
	}
	pid = pipe_exec2(p, STDIN_FILENO);
	debug_printf("pipe_exec2(%s) returned: %d\n", str,  pid);
	pipe_free(&p);
	if (pid > 0)
	{
		debug_printf("waiting %s (%d) to finish\n", str, pid);
		set_awaited_process(pid);
		wait_child(pid);
		debug_printf("%s finished\n", str);
		set_awaited_process(0);
		restore_stdin();
		restore_stdout();
	}
	free(str);
}
