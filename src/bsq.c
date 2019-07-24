#include "../includes/ft.h"
#include "../includes/section.h"
#include "../includes/t_table.h"

t_section	g_bsq = {0,0,0};
char		g_tmp[100];

void		clear_bsq()
{
	g_bsq.x = 0;
	g_bsq.y = 0;
	g_bsq.len = 0;
}

t_section	get_bsq()
{
	return (g_bsq);
}

BOOL	is_better_than_bsq(t_section new_bsq)
{
	if (new_bsq.len < g_bsq.len)
	{
		return (FALSE);
	}
	if (new_bsq.len > g_bsq.len)
	{
		return (TRUE);
	}
	if (new_bsq.y > g_bsq.y)
	{
		return (FALSE);
	}
	if (new_bsq.y < g_bsq.y)
	{
		return (TRUE);
	}
	if (new_bsq.x < g_bsq.x)
	{
		return (TRUE);
	}
	if (new_bsq.x > g_bsq.x)
	{
		return (FALSE);
	}
	return (FALSE);
}

BOOL	try_set_new_bsq(t_section new_bsq)
{
	if (is_better_than_bsq(new_bsq) )
	{
		g_bsq = new_bsq;
		_log2("new bsq found:\t", sec_to_string(g_tmp, &g_bsq));
		return (TRUE);
	}
	return (FALSE);
}

void	try_to_add_bsq_rec(t_table *node, BOOL *added)
{
	t_section	square;
	
	if (node == NULL)
	{
		*added = FALSE;
		return ;
	}
	square = try_make_square(node);
	if (square.len > 0)
	{
		if (try_set_new_bsq(square))
		{
			*added = TRUE;
		}
	}
	try_to_add_bsq_rec(node->next, added);
}

BOOL	try_to_add_bsq(t_table *new_candidates)
{
	BOOL	r;
	
	try_to_add_bsq_rec(new_candidates, &r);
	return (r);
}
