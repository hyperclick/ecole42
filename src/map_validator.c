#include "../includes/ft.h"

int		g_line_length = -1;

int		check_line(char *line, int len)
{
	if (g_line_length == -1)
	{
		g_line_length = len;
	}
	
	return (g_line_length - ft_strlen(line));
}
