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

static size_t	get_len_rec(unsigned long long int n, int base)
{
	if (n < base)
	{
		return (1);
	}
	return (get_len_rec(n % base, base) + get_len_rec(n / base, base));
}

static size_t	get_len(unsigned long long int n, int base)
{
	return (get_len_rec(n, base));
}

static char		*itoa_rec(unsigned long long int n, char *r, const char *digits)
{
	int		base;

	base = ft_strlen(digits);
	if (n < base)
	{
		*r = digits[n];
		r++;
		return (r);
	}
	return (itoa_rec(n % base, itoa_rec(n / base, r, digits), digits));
}

char* ft_itoa_base2(unsigned long long int n, const char* digits, BOOL is_negative)
{
	char	* r;
	char	* str;
	int		base;
	int		len;

	base = ft_strlen(digits);
	len = get_len(n, base);
	if (is_negative)
	{
		len++;
	}
	r = malloc(sizeof(char) * ( + 1));
	if (r == NULL)
	{
		return (r);
	}
	str = r;
	if (is_negative)
	{
		*r = '-';
		r++;
	}
	r = itoa_rec(n, r, digits);
	*r = '\0';
	return (str);

}
char* ft_itoa_base(long long int n, const char* digits)
{
	return (ft_itoa_base2(n, digits, n < 0));
}


char			*ft_itoa(long long int n)
{
	return (ft_itoa_base(n, "0123456789"));
}

char			*ft_uitoa(unsigned long long int n)
{
	return (ft_itoa_base2(n, "0123456789", FALSE));
}