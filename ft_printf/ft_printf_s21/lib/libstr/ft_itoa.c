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

#include "libstr.h"

static size_t	get_len_rec(long long n, int base)
{
	if (n < base && n > -base)
	{
		return (1);
	}
	return (get_len_rec(n % base, base) + get_len_rec(n / base, base));
}

static size_t	get_len(long long n, int base)
{
	return (n < 0 ? 1 + get_len_rec(n, base) : get_len_rec(n, base));
}

static char		*itoa_rec(long long n, char *r, const char *digits)
{
	int		base;

	base = ft_strlen(digits);
	if (n < base && n > -base)
	{
		n = n < 0 ? -n : n;
		*r = digits[n];
		r++;
		return (r);
	}
	return (itoa_rec(n % base, itoa_rec(n / base, r, digits), digits));
}

char *ft_itoa_base(long long n, const char *digits)
{
	char	*r;
	char	*str;
	int		base;

	base = ft_strlen(digits);
	r = malloc(sizeof(char) * (get_len(n, base) + 1));
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
	r = itoa_rec(n, r, digits);
	*r = '\0';
	return (str);

}


char			*ft_itoa(long long n)
{
	return (ft_itoa_base(n, "0123456789"));
}
