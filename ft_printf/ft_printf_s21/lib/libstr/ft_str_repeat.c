/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_repeat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 18:08:51 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 18:08:53 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_str_repeat(char *s, int n)
{
	char *dst;
	char *start;
	int		len;

	len = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (len * n + 1));
	start = dst;
	while (n-- > 0)
	{
		ft_strcpy(dst, s);
		dst += len;
	}
	return (start);
}
