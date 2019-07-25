/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 09:57:33 by darugula          #+#    #+#             */
/*   Updated: 2019/07/15 09:57:35 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		i;
	int		*r;

	if (tab == NULL || f == NULL)
	{
		return (tab);
	}
	r = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		r[i] = f(tab[i]);
		++i;
	}
	return (tab);
}
