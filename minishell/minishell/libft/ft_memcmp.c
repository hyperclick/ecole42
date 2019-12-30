/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				diff;

	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	if ((a == NULL && b == NULL) || n == 0)
	{
		return (0);
	}
	diff = *a - *b;
	if (diff != 0)
	{
		return (diff);
	}
	return (ft_memcmp(a + 1, b + 1, n - 1));
}
