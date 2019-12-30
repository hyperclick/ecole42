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

#include "libft.h"

char	* ft_str_left_from_rec(const char *start, const char *s, char c)
{
	if (*s == 0)
	{
			return (NULL);
	}
	if (*s == c)
	{
		//printf("start = '%s', s = '%s', %ld sub = '%s'\n", start, s, s - start - 1, ft_strsub(start, 0, s - start - 1));
		return (ft_strsub(start, 0, s - start));
	}
	return (ft_str_left_from_rec(start, s + 1, c));
}

char	* ft_str_left_from(const char *s, char c)
{
	if (*s == 0 || c == 0)
	{
		return (NULL);
	}
	return (ft_str_left_from_rec(s, s, c));
}
