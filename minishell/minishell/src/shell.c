#include "minishell.h"


void		ft_exit(int ret_code)
{
	ft_putstr("arevuar\n");
	reset_keypress();
	//free_folders();
	env_free();
	//todo: kill waited process
	//close_out_stream();
	exit(ret_code);
}


void		cd(int argc, char* const argv[])
{
	static char old_work_dir[PATH_MAX] = "";
	char folder[PATH_MAX];
	//if (argc == 0)
	//{
	//	//ft_e_putstr("-minishell: cd: missing argument - folder name\n");
	//	//return ;
	//}
	if (argc > 1)
	{
		ft_e_putstr("-minishell: cd: too many arguments\n");
		return;
	}
	ft_strcpy(folder, (argc == 0) ? env_get_value("HOME") : argv[0]);
	debug_printf("exec cd '%s'\n", folder);
	if (ft_strequ("-", folder))
	{
		if (ft_strlen(old_work_dir) == 0)
		{
			ft_e_putstr("-minishell: cd: OLDPWD not set\n");
			return;
		}
		ft_strcpy(folder, old_work_dir);
		ft_putstr(folder);
		ft_putstr("\n");
	}
	getcwd(old_work_dir, PATH_MAX - 1);
	if (chdir(folder) != 0)
	{
		ft_e_putstr("-minishell: cd: ");
		ft_e_putstr(folder);
		ft_e_putstr(": No such file or directory\n");
		return;
	}
	char tmp[255];
	debug_printf("new curdir = %s\n", getcwd(tmp, 200));
	//ft_strcpy(old_work_dir, folder);
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

char* remove_comment(char* str)
{
	//debug_printf("str = %s\n", str);
	if (*str == '#')
	{
		return ft_strdup("");
	}
	int offset = 0;
	while (TRUE)
	{
		int n = ft_str_index_of(str + offset, '#');
		if (n == -1)
		{
			return (ft_strdup(str));
		}
		//debug_printf("n = %d, offset = %d\n", n , offset);
		offset += n + 1;
		if (str[offset - 2] == ' ' || str[offset - 2] == '\t' || str[offset - 2] == ';')
		{
			return (ft_strsub(str, 0, offset - 1));
		}
	}
}

void print_prompt()
{
	ft_putstr("$> ");
}

void		ft_default_sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		if (get_awaited_process()!=0)
		{
			kill(get_awaited_process(), signum);
			ft_putchar('\n');
		}
		else
		{
			//char c = '\n';
			//write(STDIN_FILENO, &c, 1);
			clean_buffer();
			ft_putchar('\n');
			print_prompt();
		}

		return;
	}
	ft_exit(1);
}

void		unquote(char *a[])
{
	while (*a != NULL)
	{
		char* tmp = *a;
		*a = ft_strtrim2(*a, "\"'");
		free((char*) tmp);
		a++;
	}
}

int		process_one_command(char* cmd)
{
	debug_printf("cmd: '%s'\n", cmd);
	char* trimmed = ft_strtrim2(cmd, "\t ");

	if (ft_str_is_empty(trimmed))
	{
		free(trimmed);
		ft_e_putstr("minishell: syntax error near unexpected token `;'\n");
		debug_printf("minishell: syntax error near unexpected token `;'\n");
		return (1);
	}

	int	c;
	c = ft_count_words(trimmed, " \t");
	char* args[c + 1];
	args[c] = NULL;
	ft_split(args, trimmed, c, " \t");
	free(trimmed);

	unquote(args);

	char* replaced_args[c + 1];
	replaced_args[c] = NULL;
	env_replace_vars(replaced_args, (const char**)args);
	ft_free_array((void**)args, c);
	debug_printf("args = '%s' '%s'\n", replaced_args[0], replaced_args[1]);
	//ft_str_remove_empty_strings(replaced_args)
	if (!built_in_processed(replaced_args, c))
	{
		exec2(replaced_args);
	}
	//ft_putstr("free args before end loop\n");
	ft_free_array((void**)replaced_args, c);
	//free(args);
	//debug_printf("command processed: '%s'\n\n", str);
	return (0);
}

int	process_command(char* str)
{
	debug_printf("\n");
	debug_printf("entered: '%s'\n", str);
	char* trimmed = ft_strtrim2(str, "\t ");

	if (ft_str_is_empty(trimmed))
	{
		free(trimmed);
		return (0);
	}
	char* no_comments;
	debug_printf("trimmed = %s\n", trimmed);
	no_comments = remove_comment(trimmed);
	debug_printf("no comments = %s\n", no_comments);
	free(trimmed);
	if (ft_strlen(no_comments) == 0)
	{
		free(no_comments);
		return (0);
	}

	int count;

	count = ft_count_words(no_comments, ";");
	if (count == 0)
	{
		ft_e_putstr("minishell: syntax error near unexpected token `;'\n");
		debug_printf("minishell: syntax error near unexpected token `;'\n");
		free(no_comments); 
		return (1);
	}
	char* commands[count + 1];
	commands[count] = NULL;
	ft_split(commands, no_comments, count, ";");
	char** cmds = commands;
	free(no_comments);
	while (*cmds != NULL)
	{
		int r = process_one_command(*cmds);
		if (r != 0)
		{
			break;
		}
		cmds++;
	}


	ft_free_array((void**)commands, count);

	return (0);
}
