/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_try.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:29:04 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:29:06 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_max_col_width(t_table *t, int c)
{
	int		i;
	int		max;
	int		width;
	char	*cell;

	max = 0;
	i = -1;
	while (++i < t->height)
	{
		cell = get_cell(t, i, c);
		if (is_empty(cell))
		{
			continue;
		}
		width = ft_strlen(cell);
		if (max < width)
		{
			max = width;
		}
	}
	return (max);
}

void	fill_max_col_width(t_table *t)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	while (++i < t->width)
	{
		t->col_widths[++j] = get_max_col_width(t, i) + 1;
	}
	t->col_widths[j]--;
}

int		get_width_to_print(t_table *t)
{
	t->col_widths = (int *)malloc(sizeof(int) * t->width);
	fill_max_col_width(t);
	t->printed_width = ft_int_array_sum(t->col_widths, t->width);
	debug_printf("t->printed_width = %d\n", t->printed_width);
	return (t->printed_width);
}

t_table	*try_table(t_table *t)
{
	if (get_width_to_print(t) <= g_size_current.ws_col)
	{
		return (t);
	}
	else
	{
		g_table = t;
		free_table();
		return (NULL);
	}
}

t_table	*try_cols(int cols)
{
	int count;
	int rows;

	debug_printf("try_cols: %d\n", cols);
	count = ft_count_null_term_array((void **)g_options);
	rows = 0;
	while (rows * cols < count)
	{
		rows++;
	}
	if (rows == 0 || rows > g_size_current.ws_row)
	{
		return (NULL);
	}
	return (try_table(table_create(rows, cols)));
}
