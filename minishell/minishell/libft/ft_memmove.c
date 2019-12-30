/*_**************************************************************************_*/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/*_**************************************************************************_*/

#include "libft.h"

void	*ft_memmove(void *trg, const void *ptr, size_t num)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	if (ptr == NULL && trg == NULL)
		return (trg);
	dst = (unsigned char*)trg;
	src = (unsigned char*)ptr;
	if (dst > src && (size_t)(dst - src) <= num)
	{
		while (num-- != 0)
			dst[num] = src[num];
	}
	else
	{
		i = 0;
		while (i < num)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (trg);
}
