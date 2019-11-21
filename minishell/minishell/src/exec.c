#include <stdio.h>


#include "../libft/libft.h"
#include "minishell.h"

BOOL		try_execute(char* argv[], char* const envp[])
{
	if (access(argv[0], F_OK) == 0)
	{
		if (-1 == access(argv[0], X_OK))
		{
			ft_e_putstr(argv[0]);
			ft_e_putstr(": command not found\n");
			return (FALSE);
		}
		if (execve(argv[0], argv, envp) == -1)
		{
			perror("Could not execute: ");
			ft_e_putstr(argv[0]);
		}
		return (FALSE);
	}
	return (TRUE);
}

void		exec2(char* argv[], char *const envp[])
{
	pid_t pid = 0;
	int status;
	/*pid = fork();
	if (pid == -1) 
	{
		 pid == -1 means error occured
		ft_putstr("can't fork, error occured\n");
		exit(EXIT_FAILURE);
	}
	else */if (pid == 0) 
	{
		// pid == 0 means child process created 
		// getpid() returns process id of calling process 
		//printf("child process, pid = %u\n", getpid());
		char* filename = argv[0]; 
		if (!try_execute(argv, envp))
		{
			return;
		}
		char		path[PATH_MAX];
		int i = -1;
		while (++i < g_data.folders_count)
		{
			ft_strcpy(path, g_data.folders[i]);
			ft_str_append(path, PATH_SEPARATOR);
			ft_strcat(path, filename);
			argv[0] = path;
			//printf("\ntrying '%s'\n", argv[0]);
			if (!try_execute(argv, envp))
			{
				return;
			}
		}
		ft_exit(0);
	}
	else {
		// a positive number is returned for the pid of 
		// parent process 
		// getppid() returns process id of parent of  
		// calling process 
		//printf("parent process, pid = %u\n", getppid());

		// the parent process calls waitpid() on the child 
		// waitpid() system call suspends execution of  
		// calling process until a child specified by pid 
		// argument has changed state 
		// see wait() man page for all the flags or options 
		// used here  
		if (waitpid(pid, &status, 0) > 0) {

			if (WIFEXITED(status) && !WEXITSTATUS(status))
			{
			//	printf("program execution successfull\n");
			}

			else if (WIFEXITED(status) && WEXITSTATUS(status)) {
				if (WEXITSTATUS(status) == 127) {

					// execv failed 
					printf("execv failed\n");
				}
				else
					printf("program terminated normally,"
						" but returned a non-zero status\n");
			}
			else
				printf("program didn't terminate normally\n");
		}
		else {
			// waitpid() failed 
			printf("waitpid() failed\n");
		}
		//exit(0);
	}
	//return 0;

}

void		exec(const char* str, char* const envp[])
{
	int	c;

	c = ft_count_words(str, " \t");

	char* argv[c + 1];// = { "ls", "/", NULL };
	argv[c] = NULL;
	exec2(ft_split(argv, str, c, " \t"), envp);
}
