/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:48:36 by darugula          #+#    #+#             */
/*   Updated: 2019/07/10 18:48:41 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	str_cpy(char *dest, char *src)
{
	*dest = *src;
	if (*src == 0)
	{
		return ;
	}
	str_cpy(dest + 1, src + 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i++] != 0)
	{
	}
	return (i - 1);
}

char	*ft_strdup(char *src)
{
	char	*dst;

	dst = malloc(sizeof(char*) * ft_strlen(src));
	if (dst != NULL)
	{
		str_cpy(dst, src);
	}
	return (dst);
}
