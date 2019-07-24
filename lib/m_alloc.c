#include "../includes/ft.h"
#include <stdlib.h>
#include <stdio.h>

struct s_entry
{
	char name[100];
	int		size;
};

struct s_entry		entries[100000];

int		g_count = 0;


void	*m_alloc(int size, char *name)
{
	void	*p;

	ft_strcpy(entries[g_count].name, name);
	entries[g_count].size = size;
	++g_count;
	p = malloc(size);
	
	//printf("%s: %d bytes allocated to %p\n", name, size, p);
	
	return (p);
}

void		m_free(void *p, char *name)
{
	printf("%s: freeing %p\n", name, p);
	entries[g_count].size = -1;
	ft_strcpy(entries[g_count].name, name);
	
	//printf("%s\n",entries[g_count].name);
	--g_count;
	free(p);
}

int		m_get_count()
{
	return (g_count);
}
