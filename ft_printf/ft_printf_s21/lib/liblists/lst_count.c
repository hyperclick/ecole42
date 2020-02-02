/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:35:54 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 11:35:57 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	count_with_acc(t_list *elem, void *accumulator)
{
	int *p_count;

	if (elem == NULL)
	{
		return ;
	}
	p_count = (int*)accumulator;
	(*p_count)++;
}

int		lst_count(t_list *lst)
{
	int	count;

	count = 0;
	lst_reduce(lst, count_with_acc, &count);
	return (count);
}

int	lst_count_if(t_list *lst, BOOL(*predicate)(void*))
{
	int		count;

	count = 0;
	while (lst != NULL)
	{
		if (predicate(lst->content))
		{
			count++;
		}
		lst = lst->next;
	}
	return (count);
}