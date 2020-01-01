#include "minishell.h"

void		ft_exit(int ret_code)
{
	debug_printf("exit process (%d)\n", ret_code);
	reset_keypress();
	env_free();
	free_quoted_params();
	h_free();
	if (get_awaited_process() != 0)
	{
		kill(get_awaited_process(), SIGABRT);
	}
	close_out_stream();
	exit(ret_code);
}

void		init(int argc, char** argv, char** envp)
{
	set_out_file("debug_out4.txt", "w");
	set_level(1);
	save_stdin();
	save_stdout();
	debug_printf("%s\n", "started");
	debug_printf("agrc = %d\n", argc);
	debug_printf("agrv[1] = %s\n", argv[1]);
	log_line("n\n\n\nstarted\n\n");
	signal(SIGINT, ft_default_sig_handler);
	env_from_array(envp);
}


void		cd(int argc, char* const argv[])
{
	static char old_work_dir[PATH_MAX] = "";
	char folder[PATH_MAX];
	if (argc > 1)
	{
		ft_e_putstr("-minishell: cd: too many arguments\n");
		return ;
	}
	ft_strcpy(folder, (argc == 0) ? env_get_value("HOME") : argv[0]);
	debug_printf("exec cd '%s'\n", folder);
	if (ft_strequ("-", folder))
	{
		if (ft_strlen(old_work_dir) == 0)
		{
			ft_e_putstr("-minishell: cd: OLDPWD not set\n");
			return ;
		}
		debug_printf("old_work_dir = '%s'\n", old_work_dir);
		ft_strcpy(folder, old_work_dir);
		debug_printf("exec cd '%s'\n", folder);
		ft_putstr(folder);
		ft_putstr("\n");
	}
	getcwd(old_work_dir, PATH_MAX - 1);
	if (chdir(folder) != 0)
	{
		ft_e_putstr("-minishell: cd: ");
		ft_e_putstr(folder);
		ft_e_putstr(": No such file or directory\n");
		return ;
	}
	char tmp[255];
	debug_printf("new curdir = %s\n", getcwd(tmp, 200));
	//ft_strcpy(old_work_dir, folder);
}



pid_t g_awaited_process = 0;
pid_t get_awaited_process()
{
	return (g_awaited_process);
}

void set_awaited_process(pid_t pid)
{
	debug_printf("change g_awaited_process from %d to %d\n", g_awaited_process, pid);
	if ((g_awaited_process != 0 && pid != 0) || g_awaited_process == pid)
	{
		exit(1);
	}
	g_awaited_process = pid;
}

void		wait_child(pid_t pid)
{
	int status;
	// the parent process calls waitpid() on the child 
	// waitpid() system call suspends execution of  
	// calling process until a child specified by pid 
	// argument has changed state 
	debug_printf("wait %d to stop\n", pid);
	if (waitpid(pid, &status, 0) > 0)
	{
		if (WIFEXITED(status) && !WEXITSTATUS(status))
		{
			//	printf("program execution successfull\n");
		}
		else if (WIFEXITED(status) && WEXITSTATUS(status))
		{
			if (WEXITSTATUS(status) == 127)
			{
				// execv failed 
				printf("execv failed\n");
			}
			else
				debug_printf("program terminated normally,"
					" but returned a non-zero status\n");
		}
		else
			debug_printf("child program didn't terminate normally\n");
	}
	else
	{
		// waitpid() failed
		printf("waitpid() failed\n");
		debug_printf("waitpid() failed\n");
	}
	debug_printf("waitpid(%d) returned\n", pid);
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
	//debug_printf("print prompt\n");
	ft_putstr("$> ");
}

void		ft_default_sig_handler(int signum)
{
	debug_printf("signal: %d\n", signum);
	if (signum == SIGINT)
	{
		if (get_awaited_process() != 0)
		{
			kill(get_awaited_process(), signum);
			set_awaited_process(0);
			ft_putchar('\n');
		}
		else
		{
			debug_printf("no waited process\n");
			//char c = '\n';
			//write(STDIN_FILENO, &c, 1);
			clean_buffer();
			ft_putchar('\n');
			print_prompt();
		}

		return ;
	}
	ft_exit(1);
}

void		unquote(char* a[])
{
	while (*a != NULL)
	{
		char* tmp = *a;
		*a = ft_strtrim2(*a, "\"'");
		free((char*)tmp);
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

	pipe_exec(trimmed);
	//free(trimmed);

	return (0);
}

char** g_commands = NULL;

char	*trim(char *str, int *r)
{
	char	*trimmed;

	trimmed = ft_strtrim2(str, "\t ");
	free(str);
	str = NULL;
	if (ft_str_is_empty(trimmed))
	{
		free(trimmed);
		trimmed = NULL;
		*r = 0;
	}
	return (trimmed);
}

char	*remove_comment_checked(char *s, int *r)
{
	char	*no_comments;

	debug_printf("trimmed = %s\n", s);
	no_comments = remove_comment(s);
	debug_printf("no comments = %s\n", no_comments);
	free(s);
	s = NULL;
	if (ft_str_is_empty(no_comments))
	{
		free(no_comments);
		no_comments = NULL;
		*r = 0;
	}
	return (no_comments);
}

static BOOL check_words_count(char *s, int *r)
{
	int count;
	
	count = ft_count_words(s, ";");
	if (count == 0)
	{
		ft_e_putstr("minishell: syntax error near unexpected token `;'\n");
		debug_printf("minishell: syntax error near unexpected token `;'\n");
		free(s);
		*r = 1;
		return (FALSE);
	}
	return (TRUE);
}

static int process_commands(char *s)
{
	int		r;
	char	**commands;

	commands = ft_split3(s, ";");
	free(s);
	if (g_commands != NULL)
	{
		ft_e_putstr("g_commands != NULL\n");
		exit(1);
	}
	g_commands = commands;
	while (*commands != NULL)
	{
		r = process_one_command(*commands);
		if (r != 0)
		{
			break ;
		}
		commands++;
	}
	free_quoted_params();
	ft_free_null_term_array((void**)g_commands);
	g_commands = NULL;
	return (r);
}

int	process_command(const char* str)
{
	int	r;

	r = -200;
	debug_printf("\n");
	debug_printf("-----------------------\n");
	debug_printf("process command: '%s'\n", str);

	char* s = replace_quoted(str);

	if ((s= trim(s, &r)) == NULL
		|| (s = remove_comment_checked(s, &r)) == NULL
		|| !check_words_count(s, &r)
		)
	{
		return (r);
	}
	r = process_commands(s);

	debug_printf("command processed: '%s'\n", str);
	debug_printf("-------------------------\n");
	debug_printf("\n");
	return (r);
}

pid_t	built_in_or_external(char **replaced_args, int c)
{
	pid_t pid;

	pid = 0;
	if (!built_in_processed(replaced_args, c))
	{
		pid = exec2((const char**)replaced_args);
	}
	ft_free_array((void**)replaced_args, c);
	return (pid);
}

pid_t	exec(char	*str)
{
	char	**args;
	args = ft_split3(str, " \t");
	free(str);

	int c = ft_count_null_term_array((void*)args);
	char* replaced_args[c + 1];
	replaced_args[c] = NULL;
	env_replace_vars(replaced_args, (const char**)args);
	ft_free_null_term_array((void**)args);

	//parse heredoc
	//parse redirections

	replace_back(replaced_args);
	debug_printf("after replace\n");
	debug_print_zt_array((const char**)replaced_args);
	return (built_in_or_external(replaced_args, c));
}
