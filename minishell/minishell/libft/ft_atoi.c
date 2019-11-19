/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 01:51:27 by darugula          #+#    #+#             */
/*   Updated: 2019/07/09 01:51:31 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	atoi2(const char *str, long n, BOOL is_negative)
{
	int digit;

	if (*str == 0)
	{
		return (is_negative ? -n : n);
	}
	if (!ft_isdigit(*str))
	{
		return (is_negative ? -n : n);
	}
	digit = *str - '0';
	if (n > (n * 10 + digit))
	{
		return (is_negative ? 0 : -1);
	}
	str++;
	n = 10 * n + digit;
	return (atoi2(str, n, is_negative));
}

int			ft_atoi(const char *str)
{
	int			is_negative;

	while (ft_contains("\t\v\f\r\n \f", *str))
	{
		str++;
	}
	is_negative = *str == '-' ? 1 : 0;
	if (is_negative == 1 || *str == '+')
	{
		str++;
	}
	if (*str == 0)
	{
		return (0);
	}
	return ((int)atoi2(str, 0, is_negative));
}
