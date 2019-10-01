/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 22:27:26 by darugula          #+#    #+#             */
/*   Updated: 2019/07/14 22:27:28 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		str_len(char *str)
{
	int i;

	i = 0;
	while (str[i++] != 0)
	{
	}
	return (i - 1);
}

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_digit(int d)
{
	put_char('0' + d);
}

void	put_str(char *str)
{
	while (*str)
	{
		put_char(*str);
		++str;
	}
}

void	put_dup(char *str, int n)
{
	while (n-- > 0)
	{
		put_str(str);
	}
}

void	fill_with_zeroes(int *array, int len)
{
	int i;
	
	i = 0;
	while (i < len)
	{
		array[i] = 0;
		++i;
	}
}
