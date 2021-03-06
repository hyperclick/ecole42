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
	t_section bsq;
	
	bsq = get_bsq();
	
	if (new_bsq.len < bsq.len)
		return (FALSE);
	if (new_bsq.len > bsq.len)
		return (TRUE);
	if (new_bsq.y > bsq.y)
	{
		return (FALSE);
	}
	if (new_bsq.y < bsq.y)
	{
		return (TRUE);
	}
	if (new_bsq.x < bsq.x)
	{
		return (TRUE);
	}
	if (new_bsq.x > bsq.x)
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
