/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 09:54:26 by darugula          #+#    #+#             */
/*   Updated: 2019/07/17 09:54:29 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int len;

	len = 0;
	if (begin_list != NULL)
	{
		while (begin_list->next != NULL)
		{
			++len;
			begin_list = begin_list->next;
		}
		++len;
	}
	return (len);
}
