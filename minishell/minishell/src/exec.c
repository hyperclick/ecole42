#include "../libft/libft.h"
#include "minishell.h"

pid_t	ft_fork()
{
	pid_t pid;
	debug_printf("fork\n");
	pid = fork();
	if (pid == -1)
	{
		ft_e_putstr("can't fork, error occured\n");
		ft_exit(EXIT_FAILURE);
	}
	return (pid);
}

void		exec_ve(char* argv[])
{
	debug_printf("exec(%s)\n", argv[0]);
	if (execve(argv[0], argv, env_to_array()) == -1)
	{
		perror("Could not execute: ");
		ft_e_putstr(argv[0]);
		ft_exit(1);
	}
}

void		exec_ve2(const char* str)
{
	char** args = ft_split3(str, " \t");
	exec_ve(args);
	debug_printf("should not be here\n");
	ft_free_null_term_array((void**)args);
	//free(args);
}

BOOL		is_child(int pid)
{
	return (pid == 0);
}

void		fork_and_exec(char* argv[])
{
	pid_t pid;
	pid = ft_fork();
	if (is_child(pid))
	{
		exec_ve(argv);
		ft_putstr("execve succeeded\n");
		ft_exit(2);
	}

	// we are in initial process
	set_awaited_process(pid);
	wait_child(pid);
	set_awaited_process(0);
}

BOOL		try_execute(char* filename, char* argv[])
{
	if (access(argv[0], F_OK) == 0)
	{
		if (-1 == access(argv[0], X_OK))
		{
			ft_e_putstr(filename);
			ft_e_putstr(": command not found\n");
			debug_printf("%s: command found but has no exec rigths\n", filename);
			return (TRUE);
		}
		//fork_and_exec(argv);
		exec_ve(argv);
		ft_e_putstr("execve succeeded\n");
		ft_exit(2);
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
	char* argv0 = argv[0];
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
		//debug_printf("trying '%s'\n", argv[0]);
		if (try_execute(filename, argv))
		{
			argv[0] = argv0;
			ft_free_null_term_array((void**)start);
			debug_printf("executed: %s\n", path);
			//free(start);
			return;
		}
		folders++;
	}
	ft_e_putstr(filename);
	ft_e_putstr(": command not found\n");
	debug_printf("%s: command not found\n", filename);
	argv[0] = argv0;
	ft_free_null_term_array((void**)start);
	//free(start);
	return;
}