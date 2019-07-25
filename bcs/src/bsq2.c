#include "../includes/ft.h"
#include "../includes/section.h"
#include "../includes/t_table.h"
#include "../includes/file_processor.h"

void	try_to_add_bsq_rec(t_table *node, BOOL *added)
{
	t_section	square;
	
	if (node == NULL)
	{
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
	r = FALSE;
	try_to_add_bsq_rec(new_candidates, &r);
	return (r);
}
