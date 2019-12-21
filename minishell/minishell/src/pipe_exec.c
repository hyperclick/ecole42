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
void pipe_exec2(t_list* p)
{
	if (p->next == NULL)
	{
		exec_ve2((char*)p->content);
		pipe_free(&p);
		ft_exit(0);
	}
	int r;
	int w;
	ft_pipe(&r, &w);
	pid_t pid;
	pid = ft_fork();
	if (is_child(pid))
	{
		redirect(r, STDIN_FILENO);
		close_fd(w);
		pipe_exec2(p->next);
		debug_printf("should not be here2!\n");
		exit(1);
	}
	redirect(w, STDOUT_FILENO);
	close_fd(r);
	pipe_free(&p);
	exec_ve2((char*)p->content);
		debug_printf("should not be here3!\n");
		exit(1);
	set_awaited_process(pid);
	//debug_printf();
	wait_child(pid);
	set_awaited_process(0);
	ft_exit(0);
}


void pipe_exec(t_list* pipe)
{
	pid_t pid;
	pid = 0;
	pid = fork();
	if (pid == -1)
	{
		// pid == -1 means error occured
		ft_e_putstr("can't fork, error occured\n");
		ft_exit(EXIT_FAILURE);
	}
	if (is_child(pid))
	{
		pipe_exec2(pipe);
		debug_printf("should not be here!\n");
		exit(1);
	}
	pipe_free(&pipe);

	set_awaited_process(pid);
	//debug_printf();
	wait_child(pid);
	set_awaited_process(0);
}