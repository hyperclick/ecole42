#include "../includes/ft.h"
#include "../includes/t_table.h"
#include "../includes/file_processor.h"

char		g_tmp[100];


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
	char tmp[100];
	
	if (node == NULL)
	{
		_log2("table_append error: node == null for ",
			sec_to_string(g_tmp, &d));
		return NULL;
	}
	if (*node == NULL)
	{
		*node = table_create(create_heap_copy(d));
		return (*node);
	}
	if ((*node)->next == NULL)
	{
		sec_to_string(g_tmp, &d);
		sec_to_string(tmp, (*node)->data);
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

void	table_print_all(t_table *node)
{
	if (node == NULL)
	{
		return ;
	}
	ft_putstr(sec_to_table_entry(g_tmp, node->data));
	new_line();
	table_print_all(node->next);
}

void	table_print_header()
{
	t_section	bsq;
	
	bsq = get_bsq();
	ft_putstr("y\tx\tlen\tdata\t\tnode\t\tnext\n");
	sec_to_table_entry(g_tmp, &bsq);
	ft_putstr(g_tmp);
	ft_putstr("\tbsq\n");
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

int		find_compatible_lines(t_table	*current_node, t_section	*section)
{
	int		lines_found;
	
	lines_found = 0;
	while (current_node->data->y < section->y)
	{
		if (current_node->data->x == section->x
			&& current_node->data->len == section->len)
		{
			++lines_found;
		}
		current_node = current_node->next;
	}
	return (lines_found);
}

t_section	try_make_square(t_table *node)
{
	int		y_min;
	t_table	*current_node;
	t_section	*section;
	t_section	r;
	
	section = node->data;
	y_min = section->y + 1 - section->len;
	if (y_min < 0)
	{
		r.len = -1;
		return (r);
	}
	current_node = move_to(all_get_table(), y_min);
	if (find_compatible_lines(current_node, section) == section->len - 1)
	{
		r.y = y_min;
		r.x = section->x;
		r.len = section->len;
		return (r);
	}
	r.len = -1;
	return (r);
}
