#include "../includes/ft.h"
#include <fcntl.h>
//#include <stdio.h>
#include <unistd.h>

int		get_descriptor(char *logger)
{
	if (ft_strcmp(logger, "default") != 0)
	{
		ft_putstr("unknown logger");
	}
	create_directory("logs");
	return (open("log.txt", O_WRONLY));
}

void	_log2(char *logger, char *str)
{
	int		d;

	d = get_descriptor(logger);
	if (d == -1)
		return ;
	print_to_out(d, str);
	close(d);
}

void	_log(char *str)
{
	_log2("default", str);
}
