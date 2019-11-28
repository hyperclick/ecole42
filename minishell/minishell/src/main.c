#include "minishell.h"


void		ft_exit(int ret_code)
{
	ft_putstr("arevuar\n");
	//free_folders();
	env_free();
	//todo: kill waited process
	exit(ret_code);
}


void		cd(int argc, char* const argv[])
{
	if (argc <= 0)
	{
		ft_e_putstr("-minishell: cd: too many arguments");
		return ;
	}

	if (chdir(argv[0]) != 0)
	{
		ft_e_putstr("-minishell: cd: ");
		ft_e_putstr(argv[0]);
		ft_e_putstr(": No such file or directory");
		return ;
	}
}

/* reads from keypress, echoes */
int getche(void)
{
	struct termios oldattr, newattr; 
	tcgetattr(STDIN_FILENO, &oldattr);
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO); 
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
	//system("stty -echo");
	char ch;
	read(1, &ch, 1);
	//system("stty echo");
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
	return ch;
}

void		ft_default_sig_handler(int signum)
{
	(void)signum;
	ft_exit(1);
}

int main(int argc, char** argv, char** envp)
{
	//log_line("n\n\n\nstarted\n\n");

	signal(SIGINT, ft_default_sig_handler);
	//char		cmd_line[ARG_MAX];
	char		cmd_line[MAX_CMD_LINE];
	printf("qqq4\n");
	
	//ft_putstr("");

	//g_data.env = envp;
	env_add_all(envp);
	//update_folders();
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

		int	c;

		c = ft_count_words(cmd_line, " \t");

		char* args[c + 1];// = { "ls", "/", NULL };
		args[c] = NULL;
		ft_split(args, cmd_line, c, " \t");
		printf("\nargs[1] = '%s'\n", args[1]);
		if (built_in_processed(args, c))
		{
			//ft_putstr("built_in_processed");
			ft_free_array((void**)args, c);
			//free(args);
			continue;
		}
		exec2(args);
		//ft_putstr("free args before end loop\n");
		ft_free_array((void**)args, c);
		//free(args);
	}

	ft_exit(0);
	return (0);
}
