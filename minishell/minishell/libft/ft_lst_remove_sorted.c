/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:20:12 by darugula          #+#    #+#             */
/*   Updated: 2019/09/16 21:20:14 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_remove_sorted_rec(t_list* node, t_list* to_remove
	, BOOL(equal)(t_list* a, t_list* b)
	, void (*free_content)(void*, size_t))
{
	if (node->next == NULL)
	{
		return;
	}
	if (equal(node->next, to_remove))
	{
		node->next = to_remove->next;
		ft_lstdelone(&to_remove, free_content);
		return;
	}
	ft_lst_insert_sorted_rec(node->next, new, grater_than);
}
void		ft_lst_remove_sorted(t_list** list, t_list* to_remove
	, BOOL(equal)(t_list* a, t_list* b)
	, void (*free_content)(void*, size_t))
{
	if (equal(*list, to_remove))
	{
		ft_lstdelone(&to_remove, free_content);
		*list = *list->next;
		return;
	}
	ft_lst_remove_sorted_rec(*list, to_remove, equal);
}
