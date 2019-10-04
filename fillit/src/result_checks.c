#include "../libft/libft.h"
#include "tetramino.h"

BOOL	is_empty(t_elem e)
{
	return (e == EMPTY_ELEM2);
}

BOOL	is_not_empty(t_elem e)
{
	return (!is_empty(e));
}

BOOL	is_out_of_square(t_r r, int row, int col)
{
	return (row < 0 || col < 0 || row >= r.height || col >= r.width);
}

BOOL	is_overlap(t_r r, int row, int col)
{
	return (!is_empty(r.a[row][col]));
}

BOOL	has_a_neighbour(t_r r, int row, int col)
{
	return (
			row == 0 || col == 0 || row == r.height - 1 || col == r.width - 1
			||	!is_empty(r.a[row][col - 1]) || !is_empty(r.a[row - 1][col])
			);
}

BOOL	can_append(t_r r, int row, int col, t_t t)
{
	BOOL	has_neighbour;
	
	static int q = 0;
	if (r.height == 5)
	{
		q++;
	}
	has_neighbour = FALSE;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (is_empty(t.a[i][j]))
			{
				continue;
			}
			if (is_out_of_square(r, row + i, col + j))
			{
				return (FALSE);
			}
			if (is_overlap(r, row + i, col + j))
			{
				return (FALSE);
			}
			if (!has_neighbour && has_a_neighbour(r, row + i, col + j))
			{
				has_neighbour = TRUE;
			}
		}
	}
	return (has_neighbour);
}