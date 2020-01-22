/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:29:04 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:29:06 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_coord	get_coord_by_offset(t_table *t, int offset)
{
	t_coord	c;

	c.row = offset / t->width;
	c.col = offset % t->width;
	return (c);
}

t_coord	get_active_cell_coord(t_table *t)
{
	return (get_coord_by_offset(t, get_active_cell_offset()));
}
