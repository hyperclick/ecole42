#include "../includes/ft.h"
#include <stdio.h>

int		check_line_len(char *line, int len)
{
	return (len - ft_strlen(line));
}
