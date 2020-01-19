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

void		show_usage()
{
	ft_putstr_fd( "usage: ft_select option1 option2 ...\n",STDERR_FILENO);
}


void		print_table(t_table* t)
{
	char* to_print;

	to_print = table_to_string(t);
	ft_printf_fd(STDERR_FILENO, to_print);
	//ft_tputs(to_print);
	free(to_print);
}

void		draw()
{
	if (g_table == NULL)
	{
		ft_printf("expand console please!");
	}
	else
	{
		print_table(g_table);
	}
}

void		redraw()
{
	clear();
	draw();
}

int	main(int argc, char** argv)
{
	init(argc, argv);
	if (argc == 1)
	{
		reset_keypress();
		show_usage();
		ft_exit(1);
	}
	//free_table();
	//g_table = rebuild_table();
	//draw();
	while (TRUE)
	{
		if (process_command(read_command()))
			redraw();
	}
	return (100500);
}
