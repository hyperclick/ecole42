//
//  tetramino_linq.c
//  tests
//
//  Created by Delia Arugula on 30/09/2019.
//  Copyright © 2019 Delia Arugula. All rights reserved.
//

#include "tetramino_linq.h"
#include "tetramino.h"
#include "../libft/libft.h"

BOOL	t_any(t_t	*t, int (*f)(char e))
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (f(t->a[i][j]))
			{
				return (TRUE);
			}
			++j;
		}
		++i;
	}
	return (FALSE);
}

