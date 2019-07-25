/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 00:52:54 by darugula          #+#    #+#             */
/*   Updated: 2019/07/16 00:52:58 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bool.h"

void	str_n_cpy(char *dst, char *src, unsigned int n)
{
	if (n == 0)
	{
		return ;
	}
	*dst = *src;
	if (*src == 0)
	{
		return ;
	}
	str_n_cpy(dst + 1, src + 1, n - 1);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	str_n_cpy(dest, src, n);
	return (dest);
}

BOOL	is_digit(char c)
{
	return (c >= '0' && c <= '9') ? 1 : 0;
}

BOOL	starts_with_number(char *str)
{
	if (*str == 0)
	{
		return (FALSE);
	}
	return (*str == '-') ? is_digit(*(str + 1)) : is_digit(*str);
}
