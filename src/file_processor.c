#include "../includes/ft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int		load(int fd)
{
	const int	buffer_length = 1000000;
	char		buffer[buffer_length];
	int			bytes_read;
	
	bytes_read = read(fd, buffer, buffer_length);
	while (bytes_read != 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, buffer_length);
	}
	
	return (0);
}

int		print_echo(int fout, int fin)
{
	const int	buffer_length = 1000000;
	char		buffer[buffer_length];
	int			bytes_read;

	bytes_read = read(fin, buffer, buffer_length);
	while (bytes_read != 0)
	{
		print_to_out(fout, buffer);
		bytes_read = read(fin, buffer, buffer_length);
	}
	return (0);
}

int	process_file(char *name)
{
	int			fd;
	int			r;
	
	printf("\n\n\n\n\nprocess file: '%s'\n\n\n\n\n", name);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (-1);
	r = load(fd);
	close(fd);
	return (r);
}

void	process_files(int argc, char **argv)
{
	printf("\n\n\n\n\n ==================       process files =================== \n\n\n\n\n");
	int	i;
	int	r;
	//todo: handle no args
	i = 1;
	while (i < argc)
	{
		r = process_file(argv[i]);
		if (r != 0)
		{
			ft_putstr("map error\n");
		}
		if (argc > 2)
		{
			ft_putchar('\n');
		}
		++i;
	}
}
