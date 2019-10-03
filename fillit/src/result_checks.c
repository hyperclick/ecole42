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

BOOL	r_any(t_r r, int row, BOOL(*f)(t_elem))
{
	int	j;

	j = -1;
	while (++j < r.width)
	{
		if (f(r.a[row][j]))
		{
			return (TRUE);
		}
	}
	return (FALSE);
}

t_r	r_map(t_r r, void *param, t_elem(*f)(t_elem, void*))
{
	int	j;
	int	i;

	i = -1;
	while (++i < r.height)
	{
		j = -1;
		while (++j < r.width)
		{
			(r.a[i][j] = f(r.a[i][j], param));
		}
	}
	return (r);
}

t_elem	repeat(t_elem e, void *param)
{
	return (*(t_elem*)(param));
}

t_r		r_fill_all(t_r r, t_elem value)
{
	return (r_map(r, &value, repeat));
}

BOOL	row_is_empty(int row, t_r r)
{
	return (r_any(r, row, is_not_empty));
}

BOOL	is_square(t_r r)
{
	return (ft_strequ(r.path, "321"));
	return (!row_is_empty(0, r));
}
