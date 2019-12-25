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

static void pe2(char* cmd, int r, int w, int to_close, t_list *p)
{
	//int pid = ft_fork();
	//if (is_child(pid))
	//{
		//debug_set_pname(cmd);
		redirect(r, STDIN_FILENO);
		redirect(w, STDOUT_FILENO);
		close_fd(to_close);
		///pipe_free(&p);
		(void)p;
		exec(cmd);
	//}
	//debug_printf("waiting %d > %s > %d to finish\n", r, cmd, w);
	//wait_child(pid);
	//debug_printf("%s finished\n", cmd);
	//free(cmd);
	if (w!=STDOUT_FILENO)
	{
		close_fd(w);
	}
}

static void pipe_exec2(t_list* p, int prev_r)
{
	if (p->next == NULL)
	{
		pe2(ft_strdup((char*)p->content), prev_r, STDOUT_FILENO, -1, p);
		return;
	}
	int r, w;
	ft_pipe(&r, &w);
	pe2(ft_strdup((char*)p->content), prev_r, w, r, p);
	pipe_exec2(p->next, r);
	debug_printf("pipe_exec finished\n");
}

void pipe_exec(char *str)
{
	t_list* p;
	p = pipe_parse(str);
	free(str);
	pipe_exec2(p, STDIN_FILENO);
	pipe_free(&p);
}