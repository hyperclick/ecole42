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

void	put_str(char *str)
{
	write(1, str, ft_strlen(str));
}

int		main(int argc, char **argv)
{
	const int	buffer_length = 100;
	char		buffer[buffer_length];
	int			f;
	size_t		bytes_read;

	if (argc == 1)
	{
		put_str("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		put_str("Too many arguments.\n");
		return (3);
	}
	f = open(argv[1], O_RDONLY);
	if (f == -1)
		return (-1);
	bytes_read = read(f, buffer, buffer_length);
	while (bytes_read != 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(f, buffer, buffer_length);
	}
	close(f);
}
