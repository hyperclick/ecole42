#include "../includes/ft.h"
#include <stdio.h>

int		g_line_length = -1;

int		check_line(char *line)
{
	//printf("line = %s, len  = %d\n", line, g_line_length);
	if (g_line_length == -1)
	{
		g_line_length = ft_strlen(line);
	}
	
	return (g_line_length - ft_strlen(line));
}
