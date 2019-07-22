#include "includes/ft.h"
#include <fcntl.h>

int	process_file(char *name)
{
	int		fd;
	
	
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (-1);
	//while (read(fd, buffer, buffer_length))
	{
	//	write(1, buffer, bytes_read);
	}
	return (close(fd));
}

void	process_files(int argc, char **argv)
{
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
	}
}
