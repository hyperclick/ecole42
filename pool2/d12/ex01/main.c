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
#include "ft.h"
#include <errno.h>

void	put_str(char *str)
{
	write(1, str, ft_strlen(str));
}

void	print_stream(int fd)
{
	const int	buffer_length = 10000;
	char		buffer[buffer_length];
	int			bytes_read;

	while ((bytes_read = read(fd, buffer, buffer_length - 1)))
	{
		buffer[bytes_read] = '\0';
		put_str(buffer);
	}
}

int		print_file(char *fname)
{
	int			f;

	f = (*fname == '-' && fname[1] == '\0') ? 1 : open(fname, O_RDONLY);
	if (f == -1)
	{
		put_str("cat: ");
		put_str(fname);
		put_str(": No such file or directory\n");
		return (errno);
	}
	print_stream(f);
	close(f);
	return (errno);
}

int		main(int argc, char **argv)
{
	int		i;
	int		r;

	if (argc == 1)
	{
		print_file("-");
	}
	i = 1;
	while (i < argc)
	{
		r = print_file(argv[i]);
		if (r != 0)
		{
			return (r);
		}
		++i;
	}
	return (0);
}
