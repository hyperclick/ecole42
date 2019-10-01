#include "../includes/ft.h"
#include "../includes/t_table.h"
#include "../includes/file_processor.h"

char		g_tmp[100];

void	clean_node(t_table *p)
{
	char		tmp[100];
	
	sec_to_table_entry(tmp, p->data);
	sec_to_string(g_tmp, p->data);
	m_free(p->data, tmp);
	m_free(p, g_tmp);
}

