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
	//hide_cursor();
}

/*
** Initializes the custom terminal configurations
**
** It first checks that we can access the terminal name from the environment,
** then loads the entry for the terminal name we just got,
** saves the old attributes to reset them later
** and applies our custom attributes to the terminal.
** The ids "ti" and "vi" enter alternate screen mode (so we can later give back
** the shell the way it was) and hide the cursor respectively
**
** @param		N/A
** @return		N/A
*/

struct termios old_attr;
void		init_custom_conf(void)
{
struct termios attr;
	char buf[1000];
	tgetent(buf, getenv("TERM"));
	tcgetattr(STDERR_FILENO, &old_attr);
	tcgetattr(STDERR_FILENO, &attr);
	attr.c_lflag &= ~(ICANON | ECHO);
	attr.c_cc[VMIN] = 1;
	attr.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSANOW, &attr);
	tputs(tgetstr("ti", NULL), 1, ft_putc);
	tputs(tgetstr("vi", NULL), 1, ft_putc);
}

/*
** Resets the old attributes that we saved from 'init_custom_conf'
**
** It applies the old atributes to the terminal
** The ids "ve" amd "te" exit alternate screen mode and show the cursor
** respectively.
**
** @param		N/A
** @return		N/A
*/

void	reset_default_conf(void)
{
	tcsetattr(STDERR_FILENO, TCSANOW, &old_attr);
	tputs(tgetstr("ve", NULL), 1, ft_putc);
	tputs(tgetstr("te", NULL), 1, ft_putc);
}

int	main(int argc, char** argv)
{

	//init_custom_conf();

	//reset_default_conf();
	//return 98;











	init(argc, argv);
	if (argc == 1)
	{
		show_usage();
		ft_exit(1);
	}

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
