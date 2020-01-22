/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:29:04 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:29:06 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	toggle_active_cell(void)
{
	if (!remove_if_selected(get_active_cell_offset()))
	{
		select_add(get_active_cell_offset());
	}
	dump_selection();
}

void	handle_item_deleted(int offset)
{
	int	i;

	remove_if_selected(offset);
	i = offset;
	while (++i < g_options_count + 1)
	{
		if (remove_if_selected(i))
		{
			select_add(i - 1);
		}
	}
	dump_selection();
}
