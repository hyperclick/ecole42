#include <stdio.h>
#include "../libft/libft.h"
#include "minishell.h"

void		exec(/*char cmd_line[MAX_CMD_LINE]*/)
{

	//char* argv[] = { "jim", "jams", NULL };
	//char* envp[] = { "some", "environment", NULL };
	//execve("./sub", argv, envp) == -1);
	//perror("Could not execve");


	pid_t  pid;
	int status;
	pid = fork();
	if (pid == -1) {

		// pid == -1 means error occured 
		ft_putstr("can't fork, error occured\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) {

		// pid == 0 means child process created 
		// getpid() returns process id of calling process 
		printf("child process, pid = %u\n", getpid());

		// the argv list first argument should point to   
		// filename associated with file being executed 
		// the array pointer must be terminated by NULL  
		// pointer 
		char* argv_list[] = { "/bin/ls", ".", NULL };
		//char* argv_list[] = { "pwd", NULL };

		// the execv() only return if error occured. 
		// The return value is -1 
		execv("/bin/ls", argv_list);
		exit(0);
	}
	else {
		// a positive number is returned for the pid of 
		// parent process 
		// getppid() returns process id of parent of  
		// calling process 
		printf("parent process, pid = %u\n", getppid());

		// the parent process calls waitpid() on the child 
		// waitpid() system call suspends execution of  
		// calling process until a child specified by pid 
		// argument has changed state 
		// see wait() man page for all the flags or options 
		// used here  
		if (waitpid(pid, &status, 0) > 0) {

			if (WIFEXITED(status) && !WEXITSTATUS(status))
				printf("program execution successfull\n");

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


int main()
{
	//char		cmd_line[ARG_MAX];
	char		cmd_line[MAX_CMD_LINE];
	printf("qqq4\n");
	//ft_putstr("$\n");
	//log_line("n\n\n\nstarted\n\n");

	while (TRUE)
	{
		ft_putstr("$ ");
		ft_readline(cmd_line, MAX_CMD_LINE);
		//printf("read: '%s'\n", cmd_line);
		//history.push
		//if (is_up_arrow(cmd_line))
		//{
		//	ft_strcpy(cmd_line, history.pop());
		//}
		if (built_in_processed(cmd_line))
		{
			continue;
		}
		exec();
	}

	return 0;
}
