/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:05:32 by darugula          #+#    #+#             */
/*   Updated: 2019/07/17 10:05:34 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*args;
	t_list	*first;

	args = NULL;
	first = NULL;
	while (ac > 0)
	{
		if (args == NULL)
		{
			args = ft_create_elem(av[--ac]);
			first = args;
		}
		else
		{
			args->next = ft_create_elem(av[--ac]);
			args = args->next;
		}
	}
	return (first);
}
