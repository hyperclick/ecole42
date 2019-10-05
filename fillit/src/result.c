/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:37:55 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 13:37:57 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"
#include "result_checks.h"

t_r	create_r(int width)
{
	t_r r;

	r.height = width;
	r.width = width;
	r.path[0] = 0;
	r.found = FALSE;
	r.deep = 0;
	r = r_fill_all(r, EMPTY_ELEM);
	return (r);
}

t_r	append_path(t_r r, t_elem letter)
{
	ft_str_append(r.path, letter);
	return (r);
}

t_r	append(t_r r, int row, int col, t_t t)
{
	t_r	new_r;
	int	i;
	int	j;

	new_r = append_path(r, t.letter);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (!is_empty(t.a[i][j]) && !is_out_of_square(r, row + i, col + j))
			{
				new_r.a[row + i][col + j] = t.a[i][j];
			}
		}
	}
	return (new_r);
}
