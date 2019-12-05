#include "minishell.h"
#include <stdio.h>


#include "../libft/libft.h"
#include "minishell.h"


void		wait_child(pid_t  pid)
{

	int status;
	// the parent process calls waitpid() on the child 
	// waitpid() system call suspends execution of  
	// calling process until a child specified by pid 
	// argument has changed state 
	if (waitpid(pid, &status, 0) > 0)
	{
		if (WIFEXITED(status) && !WEXITSTATUS(status))
		{
			//	printf("program execution successfull\n");
		}
		else if (WIFEXITED(status) && WEXITSTATUS(status))
		{
			if (WEXITSTATUS(status) == 127)
			{
				// execv failed 
				printf("execv failed\n");
			}
			else
				printf("program terminated normally,"
					" but returned a non-zero status\n");
		}
		else
			debug_printf("child program didn't terminate normally\n");
	}
	else
	{
		// waitpid() failed 
		printf("waitpid() failed\n");
	}
}
pid_t g_awaited_process = 0;
pid_t get_awaited_process()
{
	return (g_awaited_process);
}
void		fork_and_exec(char* argv[])
{
	pid_t pid;
	pid = 0;
	pid = fork();
	if (pid == -1)
	{
		// pid == -1 means error occured
		ft_putstr("can't fork, error occured\n");
		ft_exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		// we are in child now
		//printf("child process, pid = %u\n", getpid());

		if (execve(argv[0], argv, env_to_array()) == -1)
		{
			perror("Could not execute: ");
			ft_e_putstr(argv[0]);
			ft_exit(1);
		}
		ft_putstr("execve succeeded\n");
		ft_exit(2);
	}

		// we are in initial process
		//printf("parent process, pid = %u\n", getppid());
	g_awaited_process = pid;
	wait_child(pid);
	g_awaited_process = 0;
}

BOOL		try_execute(char* filename, char* argv[])
{
	if (access(argv[0], F_OK) == 0)
	{
		if (-1 == access(argv[0], X_OK))
		{
			ft_e_putstr(filename);
			ft_e_putstr(": command not found\n");
			return (TRUE);
		}

		fork_and_exec(argv);
			return (TRUE);

	}
	return (FALSE);
}
void		exec2(char* argv[])
{
		char* filename = argv[0]; 
		if (try_execute(filename, argv))
		{
			return;
		}
		char		*argv0 = argv[0];
			//printf("free %s\n", argv[0]);
			//free(argv[0]);
		char		path[PATH_MAX];
		char** folders;
		folders = fill_path_folders();
		char** start = folders;

		while (*folders != NULL)
		{
			ft_strcpy(path, *folders);
			ft_str_append(path, PATH_SEPARATOR);
			ft_strcat(path, filename);
			argv[0] = path;
			//printf("\ntrying '%s'\n", argv[0]);
			if (try_execute(filename, argv))
			{
				argv[0] = argv0;
				ft_free_null_term_array((void**)start);
				//ft_putstr("free folders\n");
				free(start);
				return;
			}
			folders++;
		}
		ft_e_putstr(filename);
		ft_e_putstr(": command not found\n");
		argv[0] = argv0;
		ft_free_null_term_array((void**)start);
		free(start);
		return;
}