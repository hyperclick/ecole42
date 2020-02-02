/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:20:12 by darugula          #+#    #+#             */
/*   Updated: 2019/09/16 21:20:14 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	lst_insert_after(t_list *node, t_list *new)
{
	t_list *next;

	next = node->next;
	node->next = new;
	new->next = next;
}

void	lst_append(t_list *node, t_list *new)
{
	lst_insert_after(lst_get_last(node), new);
}

void	lst_insert_sorted_rec(t_list *node, t_list *new
						, BOOL (grater_than)(t_list *a, t_list *b))
{
	if (node->next == NULL || grater_than(node->next, new))
	{
		lst_insert_after(node, new);
		return ;
	}
	lst_insert_sorted_rec(node->next, new, grater_than);
}

void	lst_insert_sorted(t_list **list, t_list *new
						, BOOL (grater_than)(t_list *a, t_list *b))
{
	if (grater_than(*list, new))
	{
		new->next = *list;
		*list = new;
		return ;
	}
	lst_insert_sorted_rec(*list, new, grater_than);
}
