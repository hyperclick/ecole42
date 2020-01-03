/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:57:20 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:57:22 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(int ret_code)
{
	debug_printf("exit process (%d)\n", ret_code);
	reset_keypress();
	env_free();
	free_commands();
	free_quoted_params();
	h_free();
	if (get_awaited_process() != 0)
	{
		kill(get_awaited_process(), SIGABRT);
	}
	close_out_stream();
	exit(ret_code);
}

void	init(int argc, char **argv, char **envp)
{
	set_out_file("debug_out4.txt");
	save_stdin();
	save_stdout();
	debug_printf("%s\n", "started");
	debug_printf("agrc = %d\n", argc);
	debug_printf("agrv[1] = %s\n", argv[1]);
	log_line("n\n\n\nstarted\n\n");
	signal(SIGINT, ft_default_sig_handler);
	env_from_array(envp);

	//process_command("echo echo1");
	//process_command("exit");
}

void	print_prompt(void)
{
	ft_putstr("$> ");
}

void	ft_default_sig_handler(int signum)
{
	debug_printf("signal: %d\n", signum);
	if (signum == SIGINT)
	{
		if (get_awaited_process() != 0)
		{
			kill(get_awaited_process(), signum);
//			debug_printf("after kill\n");
//			set_awaited_process(0);
			ft_putchar('\n');
		}
		else
		{
			debug_printf("no waited process\n");
			clean_buffer();
			ft_putchar('\n');
			print_prompt();
		}
		return ;
	}
	ft_exit(1);
}

int		process_one_command(char *cmd)
{
	char *trimmed;

	debug_printf("cmd: '%s'\n", cmd);
	trimmed = ft_strtrim2(cmd, "\t ");
	if (ft_str_is_empty(trimmed))
	{
		free(trimmed);
		ft_e_putstr("minishell: syntax error near unexpected token `;'\n");
		debug_printf("minishell: syntax error near unexpected token `;'\n");
		return (1);
	}
	pipe_exec(trimmed);
	return (0);
}
