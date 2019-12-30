/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len = MIN(len_s2, n);
	ft_memcpy(s1 + len_s1, s2, len);
	*(s1 + len_s1 + len) = 0;
	return (s1);
}
