/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino_linq.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:57:49 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 17:57:51 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"
#include "../libft/libft.h"
#include "result_checks.h"

BOOL	t_any(t_t t, int (*f)(char e))
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (f(t.a[i][j]))
			{
				return (TRUE);
			}
			++j;
		}
		++i;
	}
	return (FALSE);
}

BOOL	all_empty(t_t t)
{
	return (!t_any(t, is_not_empty));
}

BOOL	r_any(t_r r, int row, BOOL (*f)(t_elem))
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

t_r		r_map(t_r r, void *param, t_elem (*f)(t_elem, void*))
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
	e = 0;
	return (*(t_elem*)(param));
}
