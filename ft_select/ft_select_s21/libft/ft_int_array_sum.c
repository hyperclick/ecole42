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

int	ft_int_array_sum(int cols[], int size)
{
	int	sum;

	sum = 0;
	while (size-- > 0)
	{
		sum += cols[size];
	}
	return (sum);
}
