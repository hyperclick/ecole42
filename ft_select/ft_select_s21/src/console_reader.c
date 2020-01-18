/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 12:30:12 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 12:30:15 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"



char			*read_command(void)
{
	int			r;
	char		control[10];

	while ((r = read(STDIN_FILENO, &control, 4)) > 0)
	{
		control[r] = 0;
		debug_printf("entered:\t r = %d, 0: '%c' (%d)\n", r, control[0], control[0]);
		debug_printf("entered:\t = '%s'\n", control);
		return (ft_strdup(control));
	}
	if (r == 0)
	{
		ft_e_putstr("std in is all\n");
		ft_exit(3);
	}
	if (r < 0)
	{
		debug_printf("std in is corrupted\n");
		ft_exit(2);
	}
	return (NULL);
}
