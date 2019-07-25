#include "../includes/ft.h"
#include "../includes/t_table.h"
#include "../includes/file_processor.h"

char		g_tmp[100];

void			table_clean_all(t_table **pp_table)
{
	t_table		*p;
	t_table		*next;
	
	if (*pp_table == NULL)
	{
		return ;
	}
	p = *pp_table;
	while (p)
	{
		next = p->next;
		clean_node(p);
		p = next;
	}
	(*pp_table) = NULL;
}

t_table	*norm_remove_lt_len(
							t_table	**pp_table,
							t_table		*first, t_table		*prev, int len)
{
	t_table		*next;
	t_table		*p;
	
	p = *pp_table;
	first = NULL;
	prev = NULL;
	while (p)
	{
		next = p->next;
		if (p->data->len > len)
		{
			prev = p;
			if (first == NULL)
			first = p;
			p = next;
			continue;
		}
		clean_node(p);
		p = NULL;
		if (prev != NULL)
		{
			prev->next = next;
		}
		p = next;
	}
	return (first);
}

void	remove_lt_len(t_table	**pp_table, int len)
{
	if (*pp_table == NULL)
	{
		return ;
	}
	(*pp_table) = norm_remove_lt_len(pp_table, NULL, NULL, len);
}

t_table	*norm_remove_incompatible(
								  t_table	**pp_table, t_section section,
								  t_table		*first, t_table		*prev)
{
	t_table		*next;
	t_table		*p;
	
	p = *pp_table;
	while (p)
	{
		next = p->next;
		if(p->data->x != section.x || p->data->len <= section.len)
		{
			prev = p;
			if (first == NULL)
			first = p;
		}
		else
		{
			clean_node(p);
			if (prev != NULL)
			prev->next = next;
		}
		p = next;
	}
	return (first);
}

void	remove_incompatible(t_table	**pp_table, t_section section)
{
	if (*pp_table == NULL)
	return ;
	(*pp_table) = norm_remove_incompatible(pp_table, section, NULL, NULL);
}
