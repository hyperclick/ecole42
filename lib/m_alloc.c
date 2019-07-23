#include "../includes/ft.h"
#include <stdlib.h>

struct s_entry
{
	char name[100];
	int		size;
};

struct s_entry		entries[100000];

int		g_count = 0;


void	*m_alloc(int size, char *name)
{
	ft_strcpy(entries[g_count].name, name);
	entries[g_count].size = size;
	++g_count;
	return (malloc(size));
}

void		m_free(void *p, char *name)
{
	entries[g_count].size = -1;
	ft_strcpy(entries[g_count].name, name);
	
	--g_count;
	free(p);
}

int		m_get_count()
{
	return (g_count);
}
