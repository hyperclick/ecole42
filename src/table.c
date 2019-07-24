#include "../includes/ft.h"
#include "../includes/t_table.h"
#include "../includes/file_processor.h"
#include <stdio.h>

char		g_tmp[100];

char			*sec_to_table_entry(char buffer[], t_section *section)
{
	char	str[20];
	int		i;
	
	i = 0;
	ft_itoa(section->y, str);
	ft_strcpy(buffer + i, str);
	i += ft_strlen(str);
	
	ft_strcpy(buffer + i, "\t");
	i += 1;
	
	ft_itoa(section->x, str);
	ft_strcpy(buffer + i, str);
	i += ft_strlen(str);
	
	ft_strcpy(buffer + i, "\t");
	i += 1;
	
	ft_itoa(section->len, str);
	ft_strcpy(buffer + i, str);
	i += ft_strlen(str);
	
	//stprintf(buffer + i, "\t%p", section);
	
	return (buffer);
}

t_table			*table_create(t_section *data)
{
	t_table		*t;
	
	if (data == NULL)
	{
		_log("ERROR\tcan't create node for section = NULL\n");
		return (NULL);
	}
	t = m_alloc(sizeof(t_table), sec_to_table_entry(g_tmp, data));
	t->data = data;
	t->next = NULL;
	return (t);
}

t_table			*table_append(t_table **node, t_section d)
{
	if (*node == NULL)
	{
		*node = table_create(create_heap_copy(d));
		return (*node);
	}
	if ((*node)->next == NULL)
	{
		(*node)->next = table_create(create_heap_copy(d));
		return ((*node)->next);
	}
	return (table_append(&(*node)->next, d));
}

t_table			*table_append2(t_table **node, int x, int y, int len)
{
	t_section	data;
	
	data.x = x;
	data.y = y;
	data.len = len;
	
	return (table_append(node, data));
}
/*
void			table_clean_all2(t_table *node)
{
	t_table		*p;
	//printf("enter table_clean_all\n");
	if (node == NULL)
	{
		//printf("exit table_clean_all\n");
		return ;
	}
	m_free(node->data, sec_to_string(g_tmp, node->data));
	node->data = NULL;
	p = (node->next);
	m_free(node, g_tmp);
	node = NULL;
	table_clean_all2(p);
}*/
/*
void			table_clean_all(t_table **pp_table)
{
	char		tmp[100];
	t_table		**p;
	//printf("enter table_clean_all\n");
	if (*pp_table == NULL)
	{
		//printf("exit table_clean_all\n");
		return ;
	}
	sec_to_table_entry(tmp, (*pp_table)->data);
	m_free((*pp_table)->data, sec_to_string(g_tmp, (*pp_table)->data));
	(*pp_table)->data = NULL;
	p = &(*pp_table)->next;
	m_free((*pp_table), tmp);
	(*pp_table) = NULL;
	table_clean_all(p);
}*/

void			table_clean_all(t_table **pp_table)
{
	char		tmp[100];
	t_table		*p;
	t_table		*next;
	
	//printf("enter table_clean_all\n");
	if (*pp_table == NULL)
	{
		//printf("exit table_clean_all\n");
		return ;
	}
	p = *pp_table;
	
	while (p)
	{
		sec_to_table_entry(tmp, p->data);
		sec_to_string(g_tmp, (*pp_table)->data);
		next = p->next;
		m_free(p->data, tmp);
		m_free(p, g_tmp);
		p = next;
	}
	(*pp_table) = NULL;
}

void	table_print_all(t_table *node)
{
	//printf("enter table_clean_all\n");
	if (node == NULL)
	{
		//printf("exit table_clean_all\n");
		return ;
	}
	ft_putstr(sec_to_table_entry(g_tmp, node->data));
	printf("\t%p", node);
	new_line();
	table_print_all(node->next);
}

void	table_print_header()
{
	ft_putstr("y\tx\tlen\n");
}

t_table	*get_last_node(t_table *table)
{
	if (table == NULL)
	{
		return (NULL);
	}
	if (table->next == NULL)
	{
		return (table);
	}
	return (get_last_node(table->next));
}

void table_append_node(t_table *table, t_table *new_nodes)
{
	if (table == NULL)
	{
		_log("ERROR: not implemented for table == NULL");
		return ;
	}
	if (new_nodes == NULL)
	{
		return ;
	}
	get_last_node(table)->next = new_nodes;
}

t_table		*move_to(t_table *node, int y)
{
	if (node == NULL)
	{
		return (NULL);
	}
	if (node->data->y > y)
	{
		_log("error: node->data.y > y");
		return (NULL);
	}
	while (node->data->y < y)
	{
		node = node->next;
	}
	return (node);
}

t_section	try_make_square(t_table *node)
{
	t_table	*table;
	int		y_min;
	t_table	*current_node;
	int		lines_found;
	t_section	*section;
	t_section	r;
	
	section = node->data;
	//need to find up to len lines entries with the same x and len
	
	y_min = section->y - section->len - 1;
	if (y_min < 0)
	{
		r.len = -1;
		return (r);
	}
	table = all_get_table();
	current_node = move_to(table, y_min);
	lines_found = 0;
	while (node->data->y < section->y)
	{
		//todo: do not check all lines if not found for first
		if (node->data->x == section->x && node->data->len == section->len)
		{
			++lines_found;
		}
		node = node->next;
	}
	if (lines_found == section->len - 1)
	{
		r.y = y_min;
		r.x = section->x;
		r.len = section->len;
		return (r);
	}
	r.len = -1;
	return (r);
}

void		remove_one(t_table **pp_node, t_table **pp_prev)
{
	char		tmp[100];
	t_table		*node;
	
	if (pp_node == NULL || *pp_node == NULL)
	{
		return ;
	}
	node = *pp_node;
	if (pp_prev != NULL && *pp_prev != NULL)
	{
		(*pp_prev)->next = node->next;
	}
	
	sec_to_table_entry(tmp, node->data);
	sec_to_string(g_tmp, node->data);
	m_free(node->data, tmp);
	m_free(node, g_tmp);
	*pp_node = NULL;
	
}
/*
void	remove_uncompatible_candidates(t_table	**pp_node, t_table **pp_prev)
{
	t_table		*node;
	t_table		*next;
	
	if (pp_node == NULL)
	{
		return ;
	}
	node = *pp_node;
	
	next = node->next;
	if (node->data->len <= get_bsq().len)
	{
		remove_one(pp_node, pp_prev);
	}
	else
	{
		*pp_prev = node;
	}
	remove_uncompatible_candidates(&next, pp_prev);
}
*/



void	remove_less_than_len(t_table	**pp_table, int len)
{
	char		tmp[100];
	t_table		*p;
	t_table		*next;
	t_table		*first;
	
	if (*pp_table == NULL)
	{
		return ;
	}
	p = *pp_table;
	first = NULL;
	while (p)
	{
		next = p->next;
		if (p->data->len <= len)
		{
			sec_to_table_entry(tmp, p->data);
			sec_to_string(g_tmp, (*pp_table)->data);
			m_free(p->data, tmp);
			m_free(p, g_tmp);
			p = NULL;
		}
		else if (first == NULL)
		{
			first = p;
		}
		p = next;
	}
	(*pp_table) = first;
	
	
}


