/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 00:58:57 by darugula          #+#    #+#             */
/*   Updated: 2019/07/16 00:59:00 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"

BOOL	is_digit(char c);
BOOL	starts_with_number(char *str);

char	*uitoa(int n, char *r)
{
	if (n < 10)
	{
		*r = (char)('0' + n);
		r++;
		return (r);
	}
	return (uitoa(n % 10, uitoa(n / 10, r)));
}

char	*itoa(int n, char *r)
{
	char *str;

	str = r;
	if (n < 0)
	{
		*r = '-';
		r++;
		n = -n;
	}
	r = uitoa(n, r);
	*r = '\0';
	return (str);
}

int		atoi_unchecked(char *str, int n)
{
	if (*str == 0)
	{
		return (n);
	}
	if (!is_digit(*str))
	{
		return (n);
	}
	return (atoi_unchecked(str + 1, n * 10 + *str - '0'));
}

int		atoi(char *str)
{
	if (!str || *str == 0)
	{
		return (0);
	}
	return ((*str == '-') ? -atoi_unchecked(++str, 0) : atoi_unchecked(str, 0));
}

BOOL	try_parse(char *str, int *n)
{
	if (!starts_with_number(str))
	{
		return (FALSE);
	}
	*n = atoi(str);
	return (TRUE);
}
