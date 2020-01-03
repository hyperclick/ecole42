/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 12:26:24 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 12:26:25 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "minishell.h"

void		fork_and_exec(const char *argv[], pid_t *ppid)
{
	*ppid = ft_fork();
	if (is_child(*ppid))
	{
		debug_set_pname(argv[0]);
		close_g_fd_to_close();
		//debug_printf("fork_and_exec:\tabout to launch %s\n", argv[0]);
		exec_ve(argv);
		debug_printf("!!!should not be here!!!\n");
	}
	debug_printf("fork_and_exec:\t%s = %d launched\n", argv[0], *ppid);
}

BOOL is_regular_file(const char* path)
{
	struct stat path_stat;
	lstat(path, &path_stat);
	return S_ISREG(path_stat.st_mode);
}

BOOL		try_execute(const char *filename, const char *argv[], pid_t *ppid)
{
	*ppid = 0;
	if (access(argv[0], F_OK) == 0)
	{
		if (-1 == access(argv[0], X_OK))
		{
			ft_e_putstr(filename);
			ft_e_putstr(": command found but has no exec rigths\n");
			debug_printf("%s: command found but has no exec rigths\n", argv[0]);
			return (TRUE);
		}
		if (!is_regular_file(argv[0]))
		{
			ft_e_putstr("-minishell: ");
			ft_e_putstr(filename);
			ft_e_putstr(": not a file\n");
			debug_printf("%s is not regular file\n", argv[0]);
			return (TRUE);
		}
		fork_and_exec(argv, ppid);
		return (TRUE);
	}
	return (FALSE);
}

pid_t		process_folders(char **folders, const char *filename
							, const char **argv)
{
	char	path[PATH_MAX];
	pid_t	pid;

	while (*folders != NULL)
	{
		ft_strcpy(path, *folders);
		ft_str_append(path, PATH_SEPARATOR);
		ft_strcat(path, filename);
		argv[0] = path;
		if (try_execute(filename, argv, &pid))
		{
			debug_printf("exec2:\texecuted: %s\n", path);
			return (pid);
		}
		folders++;
	}
	ft_e_putstr(filename);
	ft_e_putstr(": command not found\n");
	debug_printf("%s: command not found\n", filename);
	return (0);
}

pid_t		exec2(const char *argv[])
{
	const char	*filename;
	pid_t		pid;
	char		**folders;

	filename = argv[0];
	if (ft_str_starts_with(filename, "./") 
		&& try_execute(filename, argv, &pid))
	{
		return (pid);
	}
	folders = fill_path_folders();
	pid = process_folders(folders, filename, argv);
	argv[0] = filename;
	ft_free_null_term_array((void**)folders);
	return (pid);
}
