/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 03:20:26 by darugula          #+#    #+#             */
/*   Updated: 2019/07/05 03:20:32 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

void	ft_swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*ft_strrev(char *str)
{
	int size;
	int i;

	size = ft_strlen(str);
	i = 0;
	while (i < size / 2)
	{
		ft_swap(str + i, str + size - i - 1);
		i++;
	}
	return (str);
}
