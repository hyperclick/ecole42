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

#include "ft_select.h"

char** g_options = NULL;
int		g_options_count = -1;
t_table* g_table = NULL;
struct winsize size_used;
struct winsize g_size_current;
BOOL		g_show_selection = FALSE;

void		show_selection()
{
	g_show_selection = TRUE;
}


void	ft_exit(int ret_code)
{
	debug_printf("exit process (%d)\n", ret_code);

	reset_keypress();
	if (g_show_selection)
	{
		print_selection(g_options);
	}
	if (g_options != NULL)
	{
		ft_free_array((void **)g_options, g_options_count);
	}
	free_table();
	free_selected();

	close_out_stream();
	exit(ret_code);
}

char** from_arc_argv(int argc, char **argv)
{
	char** r;
	char** start_r;

	r = (char**)malloc(sizeof(char*) * (argc + 1));
	start_r = r;
	r[argc] = NULL;
	while (argc-- > 0)
	{
		char* w = ft_strdup(*argv++);
		*r = w;
		r++;
	}
	return (start_r);
}

void update_hw()
{
	ioctl(STDERR_FILENO, TIOCGWINSZ, &g_size_current);
	debug_printf("lines %d\n", g_size_current.ws_row);
	debug_printf("columns %d\n", g_size_current.ws_col);
}

void		sig_tstp_handler()
{
	reset_keypress();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}
void		sig_cont_handler()
{
	set_keypress();
	set_signal_handlers();
	redraw();
}

t_table* rebuild_table()
{
	int count;

	free_table();
	count = ft_count_null_term_array((void**)g_options);
	while (count > 0)
	{
		if ((g_table = try_cols(count--)) != NULL)
		{
			return (g_table);
		}
	}
	return (NULL);
}

void		sig_winch_handler()
{
	update_hw();
	rebuild_table();
	redraw();
	hide_cursor();
}

void	exit_signal_handler()
{
	reset_keypress();
	ft_exit(2);
}

void		sig_handler(int signum)
{
	debug_printf("\n");
	debug_printf("\n");
	debug_printf("-----------------------\n");
	debug_printf("signal %d\n", signum);
	if (signum == SIGWINCH)
	{
		sig_winch_handler();
	}
	if (signum == SIGTSTP)
	{
		sig_tstp_handler();
	}
	if (signum == SIGCONT)
	{
		sig_cont_handler();
	}
	if (signum == SIGABRT || signum == SIGINT || signum == SIGSTOP|| signum == SIGKILL|| signum == SIGQUIT )
	{
		exit_signal_handler();
	}
}

void		set_signal_handlers()
{
	signal(SIGWINCH, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGCONT, sig_handler);
	signal(SIGABRT, sig_handler);
	signal(SIGINT, sig_handler);
	signal(SIGSTOP, sig_handler);
	signal(SIGKILL, sig_handler);
	signal(SIGQUIT, sig_handler);
}

void	init(int argc, char **argv)
{
	set_out_file("debug_out4.txt");
	debug_printf("%s\n", "started");
	debug_printf("agrc = %d\n", argc);
	//debug_print_array(argc, (const char**) argv);
	log_line("n\n\n\nstarted\n\n");
	g_options = from_arc_argv(argc - 1, argv + 1);
	g_options_count = argc - 1;
	alloc_selected(g_options_count);
	//update_hw();
	set_signal_handlers();
	set_keypress();
	set_active_cell_offset(0);
	sig_winch_handler();
}
