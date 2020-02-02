/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:20:43 by darugula          #+#    #+#             */
/*   Updated: 2019/09/16 21:20:44 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

static void	copy_list(t_list *dst, t_list *src, t_list *(*f)(t_list *elem))
{
	t_list	*node;

	if (src == NULL)
	{
		return ;
	}
	node = f(src);
	dst->next = node;
	if (node == NULL)
	{
		return ;
	}
	copy_list(node, src->next, f);
}

t_list		*lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;

	if (lst == NULL || f == NULL)
	{
		return (NULL);
	}
	head = f(lst);
	if (head == NULL)
	{
		return (NULL);
	}
	copy_list(head, lst->next, f);
	return (head);
}
