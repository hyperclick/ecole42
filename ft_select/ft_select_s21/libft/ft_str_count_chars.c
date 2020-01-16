/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_count_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:10:53 by darugula          #+#    #+#             */
/*   Updated: 2019/09/10 11:10:55 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_count_chars(const char *str, const char find)
{
	int	count;

	count = 0;
	while (*str != 0)
	{
		if (*str == find)
		{
			++count;
		}
		++str;
	}
	return (count);
}
