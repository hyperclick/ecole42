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

char* ft_str_replace2(char* dst, const char* src, const char* find, const char* replace)
{
	size_t	len_before_find;
	size_t	len_after_find;
	size_t	len_src;
	size_t	len_find;
	size_t	len_replace;
	char* found;

	found = ft_strstr(src, find);
	if (found == NULL)
	{
		dst = ft_strcpy(dst, src);
		return (dst);
	}
	len_before_find = found - src;
	ft_memcpy(dst, src, len_before_find);
	len_src = ft_strlen(src);
	len_find = ft_strlen(find);
	len_replace = ft_strlen(replace);
	len_after_find = len_src - (len_before_find + len_find);
	//debug_printf("len_dst = %d, len_replace = %d, len_after_find = %d\n", ft_strlen(dst), len_replace, len_after_find);
	ft_memcpy(dst + len_before_find, replace, len_replace);
	ft_memcpy(dst + len_before_find + len_replace, src + len_before_find + len_find, len_after_find);
	//debug_printf("src = '%s', find = '%s', replace = '%s', dst = '%s'\n", src, find, replace, dst);

	return (dst);
}

char* ft_str_replace(const char* src, const char* find, const char* replace)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	len_find;
	size_t	len_replace;
	char* dst;

	len_src = ft_strlen(src);
	len_find = ft_strlen(find);
	len_replace = ft_strlen(replace);
	len_dst = len_src - len_find + len_replace + 1;
	dst = (char*)malloc(sizeof(char) * len_dst);
	dst[len_dst - 1] = 0;
	return (ft_str_replace2(dst, src, find, replace));
}