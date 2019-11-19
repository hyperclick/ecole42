/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:35:54 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 11:35:57 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_count(t_list *elem, void *accumulator)
{
	int *p_count;

	if (elem == NULL)
	{
		return ;
	}
	p_count = (int*)accumulator;
	(*p_count)++;
}

int		ft_lst_count(t_list *lst)
{
	int	count;

	count = 0;
	ft_lst_reduce(lst, ft_count, &count);
	return (count);
}
