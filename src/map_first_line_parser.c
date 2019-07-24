#include "../includes/ft.h"
#include <stdio.h>

int		g_lines_count;
char	g_empty;
char	g_obstacle;
char	g_full;

int		get_lines_count()
{
	return g_lines_count;
}
char	get_obstacle()
{
	return g_obstacle;
}
char	get_empty()
{
	return g_empty;
}
char	get_full()
{
	return g_full;
}

int		parse_first_line(char *line)
{
	int len = ft_strlen(line);

	if (len < 4)
	{
		_log("map error: first line is less than 4 chars:\t'");
		_log(line);
		_log("'");
		return (len);
	}
	g_full = line[--len];
	g_obstacle = line[--len];
	g_empty = line[--len];
	
	if(g_full == g_obstacle || g_empty == g_obstacle || g_empty == g_full)
	{
		_log2("map error: repeated chars:\t",line);
		return (1);
	}
	
	line[len] = 0;
	if (!is_number(line))
	{
		_log2("map error: not start with number:\t",line);
		return (1);
	}
	g_lines_count = ft_atoi(line);
	if (g_lines_count < 0)
	{
		_log("map error: lines count is negative:\t'");
		_log(line);
		_log("'");
		return (g_lines_count);
	}
	//_log("first line parsed successfully");
	//printf("empty = '%c', obstacle = '%c', full = '%c', count = %d\n", get_empty(), get_obstacle(), get_full(), get_lines_count());
	return (0);
}


