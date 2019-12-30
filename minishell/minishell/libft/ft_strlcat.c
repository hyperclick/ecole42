/*_**************************************************************************_*/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/*_**************************************************************************_*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	total;
	size_t	j;

	len_s1 = ft_strlen(dst);
	len_s2 = ft_strlen(src);
	total = len_s1 + len_s2;
	j = 0;
	if (size < len_s1)
		return (len_s2 + size);
	if (size > len_s1 + 1)
	{
		while (src[j] && j < size - len_s1 - 1)
		{
			dst[len_s1 + j] = src[j];
			j++;
		}
		dst[len_s1 + j] = '\0';
	}
	return (total);
}
