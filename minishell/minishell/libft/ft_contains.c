/*_**************************************************************************_*/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:04:34 by darugula          #+#    #+#             */
/*   Updated: 2019/09/10 11:04:36 by darugula         ###   ########.fr       */
/*                                                                            */
/*_**************************************************************************_*/

#include "libft.h"

BOOL		ft_contains(const char *str, char to_find)
{
	while (*str != 0)
	{
		if (*str == to_find)
		{
			return (TRUE);
		}
		str++;
	}
	return (FALSE);
}

BOOL		ft_str_contains(const char* haystack, const char* needle)
{
	return (ft_strstr(haystack, needle) != NULL);
}