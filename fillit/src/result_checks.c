/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:40:47 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 13:40:48 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "tetramino.h"

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
			row == 0 || col == 0 || row == r.height - 1 || col == r.width - 1 ||
			!is_empty(r.a[row][col - 1]) || !is_empty(r.a[row - 1][col]));
}

BOOL	can_append(t_r r, int row, int col, t_t t)
{
	BOOL	has_neighbour;
	int		i;
	int		j;

	has_neighbour = FALSE;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (is_empty(t.a[i][j]))
				continue;
			if (is_out_of_square(r, row + i, col + j))
				return (FALSE);
			if (is_overlap(r, row + i, col + j))
				return (FALSE);
			if (!has_neighbour && has_a_neighbour(r, row + i, col + j))
				has_neighbour = TRUE;
		}
	}
	return (has_neighbour);
}
