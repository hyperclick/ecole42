/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*start;

	if (s == NULL)
	{
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	start = str;
	while (*s != 0)
	{
		*str = f(*s);
		++s;
		++str;
	}
	*str = 0;
	return (start);
}
