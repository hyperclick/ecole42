/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i_needle;

	if (*needle == 0 || (*haystack == 0 && *needle == 0))
		return ((char*)haystack);
	if (*haystack == 0)
		return (NULL);
	i_needle = 0;
	while (*haystack != 0 && len-- > 0)
	{
		if (needle[i_needle] == 0)
			return ((char*)(haystack - i_needle));
		if (*haystack == needle[i_needle])
		{
			i_needle++;
		}
		else
		{
			len += i_needle;
			haystack -= i_needle;
			i_needle = 0;
		}
		haystack++;
	}
	return (needle[i_needle] == 0 ? (char*)(haystack - i_needle) : NULL);
}
