#include "../libft/libft.h"

t_d_list* g_head = NULL;
t_d_list* g_current = NULL;
t_d_list* g_last = NULL;



BOOL		h_has_previous()
{
	return ( g_current == NULL ? g_last != NULL : g_current->prev != NULL);
}

BOOL		h_has_next()
{
	return ((g_current != NULL && g_current->list.next != NULL));
}

const char* h_get_current()
{
	return((const char*)g_current->list.content);
}
const char* h_get_previous()
{
	g_current = g_current == NULL ? g_last : g_current->prev;
	return (h_get_current());
}
const char* h_get_next()
{
	g_current = (t_d_list*)g_current->list.next;
	return (h_get_current());
}

void h_append(const char* content)
{
	t_d_list* l = ft_dlst_new(content, -1);
	l->prev = g_last;
	if (g_last == NULL)
	{
		g_last = l;
		g_head = l;
		return ;
	}
	g_last->list.next = (t_list*)l;
	g_last = l;
	g_current = NULL;
}

void		h_free()
{
	if (g_head == NULL)
	{
		return ;
	}
	ft_lst_free((t_list**)&g_head);
	g_last = NULL;
	g_current = NULL;
	if (g_head != NULL)
	{
		debug_printf("g_head != NULL\n");
		exit(1);
	}
}
