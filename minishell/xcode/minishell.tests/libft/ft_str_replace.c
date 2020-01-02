/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	not_found(char *dst, const char *src, const char *find
			, size_t *len_before_find)
{
	char	*found;

	found = ft_strstr(src, find);
	if (found == NULL)
	{
		dst = ft_strcpy(dst, src);
		return (TRUE);
	}
	*len_before_find = found - src;
	return (FALSE);
}

char	*ft_str_replace2(char *dst, const char *src, const char *find
			, const char *replace)
{
	size_t	len_before_find;
	size_t	len_after_find;
	size_t	len_src;
	size_t	len_find;
	size_t	len_replace;

	if (not_found(dst, src, find, &len_before_find))
	{
		return (dst);
	}
	ft_memcpy(dst, src, len_before_find);
	len_src = ft_strlen(src);
	len_find = ft_strlen(find);
	len_replace = ft_strlen(replace);
	len_after_find = len_src - (len_before_find + len_find);
	ft_memcpy(dst + len_before_find, replace, len_replace);
	ft_memcpy(dst + len_before_find + len_replace
			, src + len_before_find + len_find, len_after_find);
	return (dst);
}

char	*ft_str_replace(const char *src, const char *find, const char *replace)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	len_find;
	size_t	len_replace;
	char	*dst;

	len_src = ft_strlen(src);
	len_find = ft_strlen(find);
	len_replace = ft_strlen(replace);
	len_dst = len_src - len_find + len_replace + 1;
	dst = (char*)malloc(sizeof(char) * len_dst);
	dst[len_dst - 1] = 0;
	return (ft_str_replace2(dst, src, find, replace));
}
