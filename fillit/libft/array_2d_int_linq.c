//
//  tetramino_linq.c
//  tests
//
//  Created by Delia Arugula on 30/09/2019.
//  Copyright © 2019 Delia Arugula. All rights reserved.
//

#include "array_2d_int_linq.h"
#include "libft.h"

t_a2_int	a2_create(int	*a[], int	height, int	width)
{
	t_a2_int	r;

	r.a = a;
	r.height = height;
	r.width = width;
	return (r);
}
/*
BOOL	a2_any(t_a2_int a, BOOL (*f)(int e, int i, int j))
{
	int	i;
	int	j;

	i = 0;
	while (i < a.height)
	{
		j = 0;
		while (j < a.width)
		{
			if (f(a.a[i][j], i, j))
			{
				return (TRUE);
			}
			++j;
		}
		++i;
	}
	return (FALSE);
}
*/
t_a2_int	a2_map(t_a2_int a, int (*f)(int e, int i, int j))
{
	int	i;
	int	j;

	i = -1;
	while (++i < a.height)
	{
		j = -1;
		while (++j < a.width)
		{
			a.a[i][j] = (f(a.a[i][j], i, j));
		}
	}
	return (a);
}

