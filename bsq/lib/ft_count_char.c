/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:48:31 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 22:48:32 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_count_char(const char *str, const char c)
{
	int len;

	if (str == NULL)
	{
		return (0);
	}
	len = 0;
	while (*str != 0)
	{
		if (*str == c)
		{
			++len;
		}
		++str;
	}
	return (len);
}
