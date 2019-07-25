/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 22:31:35 by darugula          #+#    #+#             */
/*   Updated: 2019/07/14 22:31:37 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_array (int b[9][9], int len);
void	convert(int b[9][9], char *argv[]);
BOOL	find_next_empty_pos(int b[9][9], int *y, int *x);
BOOL	verify(int all[10]);

int		g_a[9][9];

int		g_remain_numbers[10] = {0, 9, 9, 9, 9, 9, 9, 9, 9, 9};

void	print(void)
{
	print_array(g_a, 9);
}

BOOL	no_numbers_remained(void)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		if (g_remain_numbers[i] != 0)
		{
			return (FALSE);
		}
		++i;
	}
	return (TRUE);
}


BOOL	check_col(int n)
{
	int		all[10];
	int		i;

	fill_with_zeroes(all, 10);
	i = 0;
	while (i < 9)
	{
		++all[g_a[i][n]];
		++i;
	}
	return (verify(all));
}

BOOL	check_row(int n)
{
	int		all[10];
	int		i;

	fill_with_zeroes(all, 10);
	i = 0;
	while (i < 9)
	{
		++all[g_a[n][i]];
		++i;
	}
	return (verify(all));
}

BOOL	check_rows_and_cols(void)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (!check_row(i) || !check_col(i))
		{
			return (FALSE);
		}
		++i;
	}
	return (TRUE);
}

BOOL	check_square(int s[9][9])
{
	int		all[10];
	int		i;
	int		j;

	fill_with_zeroes(all, 10);
	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			++all[s[i][j]];
			++j;
		}
		j = 0;
		++i;
	}
	return (verify(all));
}

void	get_square(int s[9][9], int y, int x)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			s[i][j] = g_a[y + i][x + j];
			++j;
		}
		j = 0;
		++i;
	}
}

BOOL	check_squares(void)
{
	int		i;
	int		j;
	int		s[9][9];

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			get_square(s, i, j);
			if (!check_square(s))
			{
				return (FALSE);
			}
			j += 3;
		}
		j = 0;
		i += 3;
	}
	return (TRUE);
}

void	refill_remain_number(int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	g_remain_numbers[n] = 9;
	while (i < 9)
	{
		while (j < 9)
		{
			if (g_a[i][j] == n)
			{
				--g_remain_numbers[n];
				if (g_remain_numbers[n] < 0)
				{
					put_str("state.remain_numbers[%d] = %d");
				}
			}
			++j;
		}
		j = 0;
		++i;
	}
}

void	refill_remain_numbers(void)
{
	int		i;

	i = 1;
	while (i < 10)
	{
		refill_remain_number(i);
		++i;
	}
}

int		solve(int i, int j)
{
	int			k;

	if (!find_next_empty_pos(g_a, &i, &j))
	{
		return (0);
	}
	g_a[i][j] = 10;
	k = 0;
	while (++k < 10)
	{
		refill_remain_numbers();
		if (g_remain_numbers[k] == 0)
		{
			continue;
		}
		g_a[i][j] = k;
		if (!(check_rows_and_cols() && check_squares()) || solve(i, j) == 3)
		{
			g_a[i][j] = 10;
			continue;
		}
		return (0);
	}
	g_a[i][j] = 0;
	return (3);
}

int		solve_sudoku(char *argv[])
{
	convert(g_a, argv);
	return (solve(0, 0));
}
