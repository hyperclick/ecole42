/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*strrchr_rec(const char *s, int c, size_t len)
{
	if (s[len] == c)
	{
		return ((char*)(s + len));
	}
	if (len == 0)
	{
		return (NULL);
	}
	return (strrchr_rec(s, c, len - 1));
}

char			*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	return (strrchr_rec(s, c, len));
}
