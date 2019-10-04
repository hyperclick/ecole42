
#include "tetramino.h"


t_t		g_figures[26];
int		g_figures_count;


t_t	get_figure(char letter)
{
	return (g_figures[letter - 'A']);
}

char	*make_rest(char *rest)
{
	int		i;
	char	*start;
	
	start = rest;
	i = -1;
	while (++i < g_figures_count)
	{
		*rest = g_figures[i].letter;
		rest++;
	}
	*rest = 0;
	return (start);
}
