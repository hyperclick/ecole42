#include "../includes/ft.h"
#include "../includes/section.h"

t_section	g_bsq = {0,0,0};

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
		return (TRUE);
	}
	return (FALSE);
}
