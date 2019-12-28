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
	int r;
	r = execve(argv[0], argv, env_to_array());
	if (r == -1)
	{
		perror("Could not execute: ");
		ft_e_putstr(argv[0]);
		ft_exit(1);
	}
	debug_printf("execve returned: %d\n", r);
	ft_exit(2);
}

void		exec_ve2(const char* str)
{
	char** args = ft_split3(str, " \t");
	exec_ve(args);
	debug_printf("should not be here\n");
	ft_free_null_term_array((void**)args);
	//free(args);
}

BOOL		is_child(pid_t pid)
{
	return (pid == 0);
}

void		fork_and_exec(char* argv[], pid_t* ppid)
{
	//pid_t pid;
	*ppid = ft_fork();
	if (is_child(*ppid))
	{
		debug_set_pname(argv[0]);
		close_g_fd_to_close();
		debug_printf("fork_and_exec:\tabout to launch %s\n", argv[0]);
		exec_ve(argv);
		debug_printf("!!!should not be here!!!\n");
	}

	debug_printf("fork_and_exec:\t%s = %d launched\n", argv[0], *ppid);
	//set_awaited_process(pid);
	//wait_child(pid);
	//set_awaited_process(0);
	//add awaited process
}

BOOL		try_execute(char* filename, char* argv[], pid_t* ppid)
{
	if (access(argv[0], F_OK) == 0)
	{
		if (-1 == access(argv[0], X_OK))
		{
			ft_e_putstr(filename);
			ft_e_putstr(": command found but has no exec rigths\n");
			debug_printf("%s: command found but has no exec rigths\n", argv[0]);
			return (TRUE);
		}
		fork_and_exec(argv, ppid);
		//exec_ve(argv);
		//ft_e_putstr("execve succeeded\n");
		//ft_exit(2);
		return (TRUE);
	}
	return (FALSE);
}

pid_t		exec2(char* argv[])
{
	char* filename = argv[0];
	pid_t pid;
	if (try_execute(filename, argv, &pid))
	{
		return (pid);
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
		if (try_execute(filename, argv, &pid))
		{
			argv[0] = argv0;
			ft_free_null_term_array((void**)start);
			debug_printf("exec2:\texecuted: %s\n", path);
			//free(start);
			return (pid);
		}
		folders++;
	}
	ft_e_putstr(filename);
	ft_e_putstr(": command not found\n");
	debug_printf("%s: command not found\n", filename);
	argv[0] = argv0;
	ft_free_null_term_array((void**)start);
	//free(start);
	return (0);
}