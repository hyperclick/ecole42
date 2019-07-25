/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:24:42 by darugula          #+#    #+#             */
/*   Updated: 2019/07/17 10:24:43 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (begin_list == NULL)
	{
		return (NULL);
	}
	while (begin_list != NULL && nbr-- != 0)
	{
		begin_list = begin_list->next;
	}
	return (begin_list);
}
