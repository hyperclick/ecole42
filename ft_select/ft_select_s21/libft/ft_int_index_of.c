/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:04:34 by darugula          #+#    #+#             */
/*   Updated: 2019/09/10 11:04:36 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_index_of(int *a, int size, int value)
{
	while (--size >= 0)
	{
		if (a[size] == value)
		{
			return (size);
		}
	}
	return (-1);
}