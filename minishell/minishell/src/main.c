#include <stdio.h>
#include "../libft/libft.h"
#include "minishell.h"

void		ft_exit(int ret_code)
{
	exit(ret_code);
}


void		cd(int argc, char** argv)
{
	if (argc <= 0)
	{
		ft_e_putstr("-minishell: cd: too many arguments");
		return ;
		argv[0] = 0;
	}
}


int main(int argc, char** argv, char** envp)
{
	//char		cmd_line[ARG_MAX];
	char		cmd_line[MAX_CMD_LINE];
	printf("qqq4\n");
	char* path = env_extract_value(envp, "PATH=");
	ft_putstr(path);
	int count = ft_count_words(path, ":");
	char		*folders[count + 1];
	folders[count] = NULL;
	ft_split(folders, path, count, ":");
	printf("\npath[0] = '%s'\n", folders[0]);
	g_data.folders = folders;
	g_data.folders_count = count;
	g_data.max_folders_count = count;
	//log_line("n\n\n\nstarted\n\n");
	if (argc > 1)
	{
		cd(argc - 1, argv + 1);
	}
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
		if (ft_str_is_empty(ft_strtrim(cmd_line)))
		{
			continue;
		}
		//ft_putstr(cmd_line);
		if (built_in_processed(cmd_line))
		{
			continue;
		}
		exec(cmd_line, envp);
	}

	ft_exit(0);
	return (0);
}
