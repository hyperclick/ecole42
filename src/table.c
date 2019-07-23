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
	
	t = m_alloc(sizeof(t_table), sec_to_table_entry(g_tmp, data));
	t->data = data;
	t->next = NULL;
	return (t);
}

t_table			*table_append(t_table *node, t_section *data)
{
	if (node == NULL)
	{
		return (table_create(data));
	}
	if (node->next == NULL)
	{
		node->next = table_create(data);
		return (node->next);
	}
	return (table_append(node->next, data));
}

void	table_clean_all(t_table *node)
{
	//printf("enter table_clean_all\n");
	if (node == NULL)
	{
		//printf("exit table_clean_all\n");
		return ;
	}
	m_free(node, sec_to_table_entry(g_tmp, node->data));
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
