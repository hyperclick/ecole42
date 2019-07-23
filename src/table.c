#include "../includes/ft.h"
#include "../includes/t_table.h"
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
	sec_to_table_entry(tmp, p->data);
	sec_to_string(g_tmp, (*pp_table)->data);
	
	while (p)
	{
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
