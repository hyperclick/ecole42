/*_**************************************************************************_*/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:32:17 by darugula          #+#    #+#             */
/*   Updated: 2019/07/09 15:32:24 by darugula         ###   ########.fr       */
/*                                                                            */
/*_**************************************************************************_*/

#include "libft.h"
#include <string.h>

char	*ft_strtrim2(char const *s, char const *whitespaces)
{
	char	*str;
	int		i;
	int		len;

	if (s == NULL)
	{
		return (NULL);
	}
	while (ft_contains(whitespaces, *s))
	{
		s++;
	}
	//printf("   s = '%s'\n", s);
	len = ft_strlen(s);
	i = 0;
	if (len != 0)
	{
		while (len - 1 - i >= 0 && ft_contains(whitespaces, s[len - 1 - i]))
		{
			i++;
		}
	}
	str = ft_strndup(s, len - i);
	//printf("   str = '%s'\n", str);
	return (str);
}

char		*ft_strtrim(char const *s)
{
	return (ft_strtrim2(s, " \n\t"));
}
