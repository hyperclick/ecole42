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

void	show_usage(void)
{
	ft_putstr_fd("usage: ft_select option1 option2 ...\n", STDERR_FILENO);
}

int		main(int argc, char **argv)
{
	init(argc, argv);
	if (argc == 1)
	{
		show_usage();
		ft_exit(1);
	}
	set_keypress();
	set_active_cell_offset(0);
	sig_winch_handler();
	while (TRUE)
	{
		if (process_command(read_command()))
			redraw();
	}
	return (100500);
}
