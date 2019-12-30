/*_**************************************************************************_*/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:18:50 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:18:52 by darugula         ###   ########.fr       */
/*                                                                            */
/*_**************************************************************************_*/

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*dst;

	dst = (unsigned char*)ptr;
	while (num != 0)
	{
		dst[--num] = (unsigned char)value;
	}
	return (ptr);
}
