#include "../includes/ft.h"
#include "../includes/t_table.h"
#include <stdio.h>

char		g_tmp[100];

t_table *g_table = NULL;

t_table		*all_get_table()
{
	return (g_table);
}

void	all_append_new_candidates(t_table *new_candidates)
{
	if (new_candidates == NULL)
	{
		return ;
	}
	if (g_table == NULL)
	{
		g_table = new_candidates;
		return ;
	}
	table_append_node(g_table, new_candidates);
}
