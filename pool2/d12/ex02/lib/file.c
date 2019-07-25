/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:26:46 by darugula          #+#    #+#             */
/*   Updated: 2019/07/18 19:26:49 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../includes/ft.h"
#include <errno.h>

void	read_file(int fd)
{
	const int	buffer_length = 100;
	char		buffer[buffer_length];
	int			bytes_read;

	while ((bytes_read = read(fd, buffer, buffer_length)))
	{
	}
}

void	print_stream(int fd, int offset)
{
	const int	buffer_length = 10000;
	char		buffer[buffer_length];
	int			bytes_read;
	int			r;

	bytes_read = read(fd, buffer, offset);
	if (bytes_read < offset)
	{
		buffer[bytes_read] = '\0';
		ft_putstr(buffer);
		ft_putstr("\n");
		return ;
	}
	r = lseek(fd, -offset, SEEK_END);
	if (r >= 0)
	{
		bytes_read = read(fd, buffer, offset);
		buffer[bytes_read] = '\0';
		ft_putstr(buffer);
		return ;
	}
}

int		print_file_tail(char *fname, int offset, BOOL print_file_name)
{
	int			f;

	f = open(fname, O_RDONLY);
	if (f == -1)
	{
		ft_putstr("tail: ");
		ft_putstr(fname);
		ft_putstr(": No such file or directory\n");
		return (errno);
	}
	if (print_file_name)
	{
		ft_putstr("==> ");
		ft_putstr(fname);
		ft_putstr(" <==\n");
	}
	print_stream(f, offset);
	close(f);
	return (errno);
}

int		print_file_tails(int argc, char *argv[], int i, int offset)
{
	BOOL	print_file_name;

	print_file_name = argc - i > 1;
	while (i < argc)
	{
		print_file_tail(argv[i], offset, print_file_name);
		++i;
		if (i != argc)
		{
			ft_putstr("\n");
		}
	}
	return (errno);
}
