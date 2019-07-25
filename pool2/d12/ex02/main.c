/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:27:41 by darugula          #+#    #+#             */
/*   Updated: 2019/07/18 10:27:42 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "includes/ft.h"
#include "includes/file.h"
#include <errno.h>

int		print_usage(void)
{
	ft_putstr("tail: option requires an argument -- c\n");
	ft_putstr("usage: tail [-F | -f | -r] [-q] ");
	ft_putstr("[-b # | -c # | -n #] [file ...]\n");
	return (1);
}

int		print_bad_offset(char *str)
{
	ft_putstr("tail: illegal offset -- ");
	ft_putstr(str);
	ft_putstr("\n");
	return (2);
}

int		handle_c_arg(int argc, char *argv[])
{
	int			offset;
	char		*str;
	int			n;

	n = 1;
	str = argv[n] + 2;
	if (*str == '\0')
	{
		if (argc == 2)
		{
			return (print_usage());
		}
		str = argv[++n];
	}
	if (!try_parse(str, &offset))
	{
		return (print_bad_offset(str));
	}
	if (n == argc - 1)
	{
		read_file(1);
		return (3);
	}
	return (print_file_tails(argc, argv, n + 1, offset));
}

int		main(int argc, char **argv)
{
	const int	default_offset = 223;

	if (argc == 1)
	{
		read_file(1);
		return (1);
	}
	if (0 != ft_strncmp(argv[1], "-c", 2))
	{
		return (print_file_tails(argc, argv, 1, default_offset));
	}
	else
	{
		return (handle_c_arg(argc, argv));
	}
}
