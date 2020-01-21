/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:29:04 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:29:06 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		fill_cells(t_table* t, char** src)
{
	t->cells = src;
	t->cells_count = ft_count_null_term_array((void**)src);
}

void free_table()
{
	if (g_table != NULL)
	{
		debug_printf("table freed\n");
		free(g_table->col_widths);
		free(g_table);
		g_table = NULL;
	}
}

t_table* table_create(int rows, int cols)
{
	t_table* t;

	t = (t_table*)malloc(sizeof(t_table));
	t->height = rows;
	t->width = cols;
	fill_cells(t, g_options);
	debug_printf("table (h:%d, w:%d) created\n", t->height, t->width);
	return(t);
}