/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:20:12 by darugula          #+#    #+#             */
/*   Updated: 2019/09/16 21:20:14 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void		lst_remove_sorted_rec(t_list *node, t_list *to_remove
	, BOOL (equal)(t_list *a, t_list *b)
	, void (*free_content)(void*))
{
	if (node->next == NULL)
	{
		return ;
	}
	if (equal(node->next, to_remove))
	{
		node->next = to_remove->next;
		lstdelone(&to_remove, free_content);
		return ;
	}
	lst_remove_sorted_rec(node->next, to_remove, equal, free_content);
}

void		lst_remove_sorted(t_list **list, t_list *to_remove
	, BOOL (equal)(t_list *a, t_list *b)
	, void (*free_content)(void*))
{
	if (equal(*list, to_remove))
	{
		lstdelone(&to_remove, free_content);
		*list = (*list)->next;
		return ;
	}
	lst_remove_sorted_rec(*list, to_remove, equal, free_content);
}
