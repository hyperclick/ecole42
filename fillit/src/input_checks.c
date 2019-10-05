/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:42:03 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 12:42:11 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "tetramino.h"
#include "tetramino_linq.h"
#include "result_checks.h"

BOOL		e_has_a_neighbour(t_t t, int row, int col)
{
	return (
	!is_neighbour_empty(t, row, col - 1) ||
	!is_neighbour_empty(t, row, col + 1) ||
	!is_neighbour_empty(t, row - 1, col) ||
	!is_neighbour_empty(t, row + 1, col));
}

BOOL		e_has_diag_neighbour(t_t t, int row, int col)
{
	return (
	(!is_neighbour_empty(t, row - 1, col - 1) &&
	is_neighbour_empty(t, row, col - 1) &&
	is_neighbour_empty(t, row - 1, col)) ||
	(!is_neighbour_empty(t, row - 1, col + 1) &&
	is_neighbour_empty(t, row - 1, col) &&
	is_neighbour_empty(t, row, col + 1)) ||
	(!is_neighbour_empty(t, row + 1, col - 1) &&
	is_neighbour_empty(t, row, col - 1) &&
	is_neighbour_empty(t, row + 1, col)) ||
	(!is_neighbour_empty(t, row + 1, col + 1) &&
	is_neighbour_empty(t, row, col + 1) &&
	is_neighbour_empty(t, row + 1, col)));
}

BOOL		validate_adjacent(int lines[4])
{
	int	i;

	i = 0;
	while (++i < 4 - 1)
	{
		if (lines[i] == 0 && lines[i - 1] != 0 && lines[i + 1] != 0)
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

BOOL		validate_figure2(t_t t, int filled_rows[4], int filled_cols[4])
{
	int	i;
	int	j;
	int	elements_count;

	elements_count = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!is_empty(t.a[i][j]))
			{
				if (!e_has_a_neighbour(t, i, j)
					|| e_has_diag_neighbour(t, i, j))
					return (FALSE);
				elements_count++;
				filled_rows[i] = 1;
				filled_cols[j] = 2;
			}
			++j;
		}
		++i;
	}
	return (elements_count == 4);
}

BOOL		validate_figure(t_t t)
{
	int	filled_rows[4];
	int	filled_cols[4];

	ft_bzero(filled_rows, sizeof(int) * 4);
	ft_bzero(filled_cols, sizeof(int) * 4);
	return (validate_figure2(t, filled_rows, filled_cols)
			&& validate_adjacent(filled_rows)
			&& validate_adjacent(filled_cols));
}
