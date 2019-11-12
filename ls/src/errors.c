/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:48:40 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:48:42 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void			print_no_such_file(const char arg[])
{
	ft_putstr_fd("ls: ", STDERR_FILENO);
	ft_putstr_fd(*arg == 0 ? "fts_open" : arg, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	if (*arg == 0)
	{
		exit(1);
	}
}

void			print_no_such_files(char *files[], int count)
{
	int		i;

	i = -1;
	while (++i < count)
	{
		print_no_such_file(files[i]);
	}
}
