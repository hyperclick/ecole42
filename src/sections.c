#include "../includes/ft.h"
#include "../includes/t_table.h"

t_table			*table_create(t_section *data)
{
	t_table		*t;
	char		tmp[100];
	
	t = m_alloc(sizeof(t_table), sec_to_table_entry(tmp, data));
	t->data = data;
	return (t);
}
