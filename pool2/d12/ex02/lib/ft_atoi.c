/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:02:33 by darugula          #+#    #+#             */
/*   Updated: 2019/07/18 19:02:35 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

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
	return (*str == '-') ? -atoi_unchecked(++str, 0) : atoi_unchecked(str, 0);
}

BOOL	starts_with_number(char *str)
{
	return (*str == '-' || is_digit(*str));
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
