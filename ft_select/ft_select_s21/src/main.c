/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 14:08:18 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 14:08:20 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


char* g_last_first_option = NULL;

void		show_usage()
{
	ft_putstr("usage: ft_select option1 option2 ...\n");
}


t_table* rebuild_table()
{
	int count;

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

void		print_table(t_table* t)
{
	char* to_print;

	to_print = table_to_string(t);
	ft_printf(to_print);
	free(to_print);
}

//void		move_cursor_at_start(char *first)
//{
//
//}

void		draw()
{
	g_table = rebuild_table();
	if (g_table == NULL)
	{
		ft_printf("expand console!");
	}
	else
	{
		print_table(g_table);
		//move_cursor_left(g_size_current.ws_col);
		//move_cursor_up(g_table->height - 1);
		//move_cursor_at_start(g_options[0]);
	}
	//g_last_first_option = g_options[0];
}

void		redraw()
{
	clear();
	free_table();
	draw();
}


void		sig_winch_handler(int signum)
{
	debug_printf("\n");
	debug_printf("\n");
	debug_printf("-----------------------\n");
	debug_printf("signal %d\n", signum);
	update_hw();
	redraw();
}

int	main(int argc, char** argv, char** envp)
{
	init(argc, argv, envp);
	if (argc == 1)
	{
		show_usage();
		ft_exit(1);
	}

	signal(SIGWINCH, sig_winch_handler);

	//sig_winch_handler(SIGWINCH);
	set_active_cell_offset(0);
	draw();
	while (TRUE)
	{
		process_command(read_command());
		redraw();
	}
//	ft_exit(0);
	return (100500);
}
