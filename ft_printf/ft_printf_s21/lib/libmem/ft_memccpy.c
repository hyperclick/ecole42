/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t num)
{
	unsigned char	*dst;
	unsigned char	*src;
	unsigned char	ch;
	size_t			i;

	i = -1;
	dst = (unsigned char*)d;
	src = (unsigned char*)s;
	ch = (unsigned char)c;
	while (++i < num)
	{
		dst[i] = src[i];
		if (src[i] == ch)
		{
			return (dst + i + 1);
		}
	}
	return (NULL);
}
