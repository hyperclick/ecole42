/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:16:51 by darugula          #+#    #+#             */
/*   Updated: 2019/07/17 10:16:52 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*prev;

	if (begin_list == NULL)
	{
		return ;
	}
	while (*begin_list != NULL)
	{
		prev = *begin_list;
		*begin_list = (*begin_list)->next;
		free(prev);
	}
}
