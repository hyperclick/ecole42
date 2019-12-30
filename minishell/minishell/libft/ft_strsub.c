/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, int start, int len)
{
	char	*str;

	if (s == NULL || ft_strlen(s) < start + len)
	{
		return (NULL);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	ft_strncpy(str, s + start, len);
	str[len] = 0;
	return (str);
}
