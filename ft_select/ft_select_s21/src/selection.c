/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:29:04 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:29:06 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int *g_selected = NULL;
int g_selected_count = 0;

void		alloc_selected(int size)
{
	g_selected = (int *)malloc(sizeof(int) * size);
}

void		free_selected()
{
	free(g_selected);
}

BOOL		is_selected2(int offset)
{
	return (ft_contains_int(g_selected, g_selected_count, offset));
}

BOOL		is_selected(t_table *t, int row, int col)
{
	return (is_selected2(get_offset(t, row, col)));
}