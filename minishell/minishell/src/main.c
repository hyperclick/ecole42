#include <stdio.h>
#include "../libft/libft.h"
#include "minishell.h"

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
		printf("read: '%s'\n", cmd_line);
		//history.push
		//if (is_up_arrow(cmd_line))
		//{
		//	ft_strcpy(cmd_line, history.pop());
		//}
		if (is_exit(cmd_line))
		{
			printf("exiting\n");
			return (0);
		}
	}

	return 0;
}
