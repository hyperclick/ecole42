/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:31:51 by darugula          #+#    #+#             */
/*   Updated: 2019/07/14 23:31:53 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	convert(int b[9][9], char *argv[])
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] == '.')
			{
				argv[i][j] = '0';
			}
			b[i][j] = argv[i][j] - '0';
			++j;
		}
		++i;
	}
}

BOOL	find_next_empty_pos(int b[9][9], int *y, int *x)
{
	const int	empty_number = 0;
	int			i;
	int			j;

	i = *y;
	j = *x;
	while (i < 9)
	{
		while (j < 9)
		{
			if (b[i][j] == empty_number)
			{
				*y = i;
				*x = j;
				return (TRUE);
			}
			++j;
		}
		j = 0;
		++i;
	}
	return (FALSE);
}

BOOL	verify(int all[10])
{
	int i;
	
	i = 1;
	while (i < 10)
	{
		if (all[i] > 1)
		{
			return (FALSE);
		}
		++i;
	}
	return (TRUE);
}
