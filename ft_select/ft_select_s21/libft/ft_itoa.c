/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:37:49 by darugula          #+#    #+#             */
/*   Updated: 2019/09/10 10:37:51 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len_rec(long long n)
{
	if (n < 10 && n > -10)
	{
		return (1);
	}
	return (get_len_rec(n % 10) + get_len_rec(n / 10));
}

static size_t	get_len(long long n)
{
	return (n < 0 ? 1 + get_len_rec(n) : get_len_rec(n));
}

static char		*itoa_rec(long long n, char *r)
{
	if (n < 10 && n > -10)
	{
		n = n < 0 ? -n : n;
		*r = (char)('0' + n);
		r++;
		return (r);
	}
	return (itoa_rec(n % 10, itoa_rec(n / 10, r)));
}

char			*ft_itoa(long long n)
{
	char	*r;
	char	*str;

	r = malloc(sizeof(char) * (get_len(n) + 1));
	if (r == NULL)
	{
		return (r);
	}
	str = r;
	if (n < 0)
	{
		*r = '-';
		r++;
	}
	r = itoa_rec(n, r);
	*r = '\0';
	return (str);
}
