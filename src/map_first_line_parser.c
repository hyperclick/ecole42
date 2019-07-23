#include "../includes/ft.h"

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
		return (len);
	}
	g_empty = line[--len];
	g_obstacle = line[--len];
	g_full = line[--len];
	line[len] = 0;
	g_lines_count = ft_atoi(line);
	if (g_lines_count < 0)
	{
		return (g_lines_count);
	}
	return (0);
}


