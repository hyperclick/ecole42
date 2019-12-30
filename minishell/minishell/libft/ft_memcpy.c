/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *trg, const void *ptr, size_t num)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			i;

	if (ptr == NULL && trg == NULL)
	{
		return (trg);
	}
	dst = (unsigned char*)trg;
	src = (unsigned char*)ptr;
	i = 0;
	while (i < num)
	{
		dst[i] = src[i];
		++i;
	}
	return (trg);
}
