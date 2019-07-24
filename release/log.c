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
	//printf("%s\n", str);
	print_to_out(d, str);
	print_to_out(d, "\n");
	close(d);
}

void	_log(char *str)
{
	_logger("default", str);
}

void _log2(char *a, char *b)
{
	char	buffer[ft_strlen(a) + ft_strlen(b) + 1];
	
	ft_concat(buffer, a, b);
	_log(buffer);
}

void _log3(char *a, char *b, char *c)
{
	char	buffer[ft_strlen(a) + ft_strlen(b) + ft_strlen(c) + 1];
	
	ft_concat3(buffer, a, b, c);
	_log(buffer);
}
