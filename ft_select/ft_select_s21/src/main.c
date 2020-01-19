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
	ft_printf_fd(STDERR_FILENO, to_print);
	free(to_print);
}

void		draw()
{
	g_table = rebuild_table();
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
	free_table();
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
	set_active_cell_offset(0);
	draw();
	while (TRUE)
	{
		process_command(read_command());
		redraw();
	}
	return (100500);
}
