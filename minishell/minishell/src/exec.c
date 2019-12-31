#include "../libft/libft.h"
#include "minishell.h"

pid_t	ft_fork()
{
	pid_t	pid;

	debug_printf("fork\n");
	pid = fork();
	if (pid == -1)
	{
		ft_e_putstr("can't fork, error occured\n");
		ft_exit(EXIT_FAILURE);
	}
	return (pid);
}

void		exec_ve(const char *argv[])
{
	debug_printf("exec(%s)\n", argv[0]);
	int r;
	r = execve(argv[0], (char**) argv, env_to_array());
	if (r == -1)
	{
		perror("Could not execute: ");
		ft_e_putstr(argv[0]);
		ft_exit(1);
	}
	debug_printf("execve returned: %d\n", r);
	ft_exit(2);
}

void		exec_ve2(const char *str)
{
	char	**args;

	args = ft_split3(str, " \t");
	exec_ve((const char **)args);
	debug_printf("should not be here\n");
	ft_free_null_term_array((void**)args);
}

BOOL		is_child(pid_t pid)
{
	return (pid == 0);
}

void		fork_and_exec(const char *argv[], pid_t *ppid)
{
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
}

BOOL		try_execute(const char *filename, const char *argv[], pid_t *ppid)
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
		return (TRUE);
	}
	return (FALSE);
}

BOOL		try_folder(const char* argv[], char* folder, const char *filename, pid_t	*pid)
{
	char		path[PATH_MAX];

	ft_strcpy(path, folder);
	ft_str_append(path, PATH_SEPARATOR);
	ft_strcat(path, filename);
	argv[0] = path;
	return (try_execute(filename, argv, pid));
}

BOOL		try_all_folders(const char* argv[], char	**folders, const char	*filename, pid_t *pid)
{
	while (*folders != NULL)
	{
		if (try_folder(argv, *folders, filename, pid))
		{
			return (TRUE);
		}
		folders++;
	}
	ft_e_ft_putstr_and_free(ft_strjoin(filename, ": command not found\n"));
	debug_printf("%s: command not found\n", filename);
	return (FALSE);
}

pid_t		exec_try_all_folders(const char* argv[], pid_t *pid)
{
	char	** folders;
	char	** start;
	BOOL	b;
	const char* filename;

	folders = fill_path_folders();
	start = folders;
	filename = argv[0];
	b = try_all_folders(argv, folders, filename, pid);

	argv[0] = (char *)filename;
	ft_free_null_term_array((void**)start);
	return (b);
}


pid_t		exec2(const char *argv[])
{
	pid_t	pid;
		
	if (try_execute(argv[0], argv, &pid))
	{
		return (pid);
	}
	if (exec_try_all_folders(argv, &pid))
	{
		return (pid);
	}
	return(0);
}
