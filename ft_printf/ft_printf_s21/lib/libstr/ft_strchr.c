/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strchr(const char *s, int c)
{
	if (*s == 0)
	{
		if (c == 0)
		{
			return ((char*)s);
		}
		else
		{
			return (NULL);
		}
	}
	if (*s == c)
	{
		return ((char*)s);
	}
	return (ft_strchr(s + 1, c));
}

char	*ft_str_right_from(const char *s, int c)
{
	return (ft_strchr(s, c));
}

int		ft_str_index_of(const char *s, int c)
{
	const char	*found;

	found = ft_str_right_from(s, c);
	return (found == NULL ? -1 : found - s);
}
