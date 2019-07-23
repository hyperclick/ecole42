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

void			table_clean_all(t_table *node)
{
	//printf("enter table_clean_all\n");
	if (node == NULL)
	{
		//printf("exit table_clean_all\n");
		return ;
	}
	m_free(node->data, sec_to_string(g_tmp, node->data));
	m_free(node, g_tmp);
	table_clean_all(node->next);
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
