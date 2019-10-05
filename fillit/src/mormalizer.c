#include "../libft/libft.h"
#include "tetramino.h"
#include "result_checks.h"

BOOL		row_is_empty(t_t f, int row)
{
	int	j;

	j = -1;
	while (++j < 4)
	{
		if (!is_empty(f.a[row][j]))
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

BOOL		col_is_empty(t_t f, int col)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!is_empty(f.a[i][col]))
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

t_t			move_up(t_t f)
{
	int	i;
	int j;

	i = -1;
	while (++i < 4 - 1)
	{
		j = -1;
		while (++j < 4)
		{
			f.a[i][j] = f.a[i + 1][j];
		}
	}
	j = -1;
	while (++j < 4)
	{
		f.a[i][j] = EMPTY_ELEM;
	}
	return (f);
}

t_t			move_left(t_t f)
{
	int	i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4 - 1)
		{
			f.a[i][j] = f.a[i][j + 1];
		}
	}
	i = -1;
	while (++i < 4)
	{
		f.a[i][j] = EMPTY_ELEM;
	}
	return (f);
}

t_t			normalize(t_t f)
{
	while (row_is_empty(f, 0))
	{
		f = move_up(f);
	}
	while (col_is_empty(f, 0))
	{
		f = move_left(f);
	}
	return (f);
}

