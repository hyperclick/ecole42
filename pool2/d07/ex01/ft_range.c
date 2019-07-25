/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:22:16 by darugula          #+#    #+#             */
/*   Updated: 2019/07/10 19:22:19 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*r;
	int	i;

	if (min >= max)
	{
		return (NULL);
	}
	r = malloc(sizeof(int) * (max - min));
	if (r != NULL)
	{
		i = 0;
		while (min < max)
		{
			r[i++] = min++;
		}
	}
	return (r);
}
