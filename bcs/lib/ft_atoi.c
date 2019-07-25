/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 04:20:27 by darugula          #+#    #+#             */
/*   Updated: 2019/07/05 04:20:32 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

BOOL	is_digit(char c)
{
	return (c >= '0' && c <= '9') ? 1 : 0;
}

BOOL	starts_with_number(char *str)
{
	if (str == NULL || *str == 0)
	{
		return (FALSE);
	}
	return (*str == '-') ? is_digit(*(str + 1)) : is_digit(*str);
}

BOOL	is_number(char *str)
{
	if (str == NULL || *str == 0)
	{
		return (FALSE);
	}
	if (*str == '-' || *str == '+')
	{
		++str;
	}
	if (*str == 0)
	{
		return (FALSE);
	}
	while (*str != 0)
	{
		if (!is_digit(*str))
		{
			return (FALSE);
		}
		++str;
	}
	return (TRUE);
}

int		ft_atoi(char *str)
{
	int		r;
	BOOL	is_negative;
	BOOL	is_signed;

	if (str == NULL)
	{
		return (0);
	}
	is_negative = (*str == '-');
	is_signed = is_negative || (*str == '+');
	if (is_signed)
	{
		++str;
	}
	r = 0;
	while (*str != 0)
	{
		r *= 10;
		r += *str - '0';
		++str;
	}
	return (is_negative ? -r : r);
}
