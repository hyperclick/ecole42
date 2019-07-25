#include "../includes/ft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int		get_descriptor(char *logger)
{
	if (ft_strcmp(logger, "default") != 0)
	{
		ft_putstr("unknown logger");
	}
	create_directory("logs");
	return (open("log.txt", O_WRONLY | O_APPEND | O_CREAT
				 , S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH));
}

void	_logger(char *logger, char *str)
{
	int		d;

	d = get_descriptor(logger);
	if (d == -1)
	{
		printf("failed to open file 'log.txt'");
		return ;
	}
	printf("%s\n", str);
	print_to_out(d, str);
	print_to_out(d, "\n");
	close(d);
}
