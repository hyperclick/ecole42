/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 08:39:29 by darugula          #+#    #+#             */
/*   Updated: 2019/07/17 08:39:32 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*get_last_elem(t_list *current)
{
	if (current == NULL)
	{
		return (current);
	}
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*last;

	last = get_last_elem(*begin_list);
	if (last == NULL)
	{
		*begin_list = (ft_create_elem(data));
		return ;
	}
	last->next = ft_create_elem(data);
}
