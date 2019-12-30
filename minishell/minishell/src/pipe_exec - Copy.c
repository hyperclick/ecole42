#include "minishell.h"

void log_pipe(int r, int w)
{
	debug_printf("new pipe: r=%d, w=%d\n", r, w);
}

void	ft_pipe(int* r, int* w)
{
	int fd[2];
	if (pipe(fd) != 0)
	{
		ft_e_putstr("pipe() failed\n");
		debug_printf("pipe() failed\n");
		ft_exit(1);
	}
	*r = fd[0];
	*w = fd[1];
	log_pipe(*r, *w);
}

int g_fd_to_close = -11;
void	close_g_fd_to_close()
{
	debug_printf("close_g_fd_to_close");
	close_fd(g_fd_to_close);
	g_fd_to_close = -2;
}

pid_t pe2(char* cmd, int r, int w, t_list **p)
{
	pid_t pid;
	// pid = ft_fork();
	//if (is_child(pid))
	//{
	//debug_set_pname(cmd);
	debug_printf("exec %d > %s > %d\n", r, cmd, w);
	restore_stdin();
	restore_stdout();
	redirect(r, STDIN_FILENO);
	redirect(w, STDOUT_FILENO);
	///close_fd(to_close);
	(void)p;
	//pipe_free(p);
	//exec_ve2(cmd);
	pid = (exec(cmd));
	//}
	//debug_printf("waiting %d > %s > %d to finish\n", r, cmd, w);
	//wait_child(pid);
	//debug_printf("%s finished\n", cmd);
	//free(cmd);

	if (w != STDOUT_FILENO)
	{
		close_fd(w);
	}
	return (pid);
}

pid_t pipe_exec2(t_list* p, int prev_r)
{
	if (p->next == NULL)
	{
		return pe2(ft_strdup((char*)p->content), prev_r, STDOUT_FILENO, &p);
	}
	int r, w;
	ft_pipe(&r, &w);
	g_fd_to_close = r;
	pe2(ft_strdup((char*)p->content), prev_r, w, &p);
	return (pipe_exec2(p->next, r));
}

void pipe_exec(char* str)
{
	pid_t pid;
	t_list* p;
	p = pipe_parse(str);
	//pid = ft_fork();
	//if (is_child(pid))
	//{
	debug_set_pname(str);
	//free(str);
	pid = pipe_exec2(p, STDIN_FILENO);
	debug_printf("pipe_exec2 returned: %d\n", pid);
	//	ft_exit(0);
	//}
	pipe_free(&p);
	//restore_stdin();
	//restore_stdout();
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
