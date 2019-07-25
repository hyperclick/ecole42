#include "../includes/ft.h"

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

int		_log2_and_return(char *a, char *b, int r)
{
	_log2(a, b);
	return (r);
}

void _log3(char *a, char *b, char *c)
{
	char	buffer[ft_strlen(a) + ft_strlen(b) + ft_strlen(c) + 1];
	
	ft_concat3(buffer, a, b, c);
	_log(buffer);
}

