#include "../includes/ft.h"
#include "../includes/t_table.h"
#include <stdio.h>

char		g_tmp[100];

t_table *g_table = NULL;

t_table		*all_get_table()
{
	return (g_table);
}

t_table		**all_get_table_address()
{
	return (&g_table);
}

void	all_table_clean()
{
	table_clean_all(&g_table);
}

void	all_append_new_candidates(t_table *new_candidates)
{
	//printf("g_table = %p\n", g_table);
	if (new_candidates == NULL)
	{
		return ;
	}
	if (g_table == NULL)
	{
		//printf("going to set g_table to %p\n", new_candidates);
		g_table = new_candidates;
		return ;
	}
	table_append_node(g_table, new_candidates);
}

void		all_remove_less_than_len(int len)
{
	remove_lt_len(&g_table, len);
}

void	all_remove_conflicting_sections(t_table	*node)
{
	if (node == NULL)
	{
		return ;
	}
	//printf("%s: %s\n", __func__, sec_to_string(g_tmp, node->data));
	remove_incompatible(&g_table, *node->data);
	node = node->next;
	all_remove_conflicting_sections(node);
}
