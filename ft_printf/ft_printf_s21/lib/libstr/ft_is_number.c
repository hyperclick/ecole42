/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:50:27 by darugula          #+#    #+#             */
/*   Updated: 2019/09/10 10:50:29 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

int		ft_is_number(char *str)
{
	if (*str == 0)
	{
		return (0);
	}
	while (*str != 0)
	{
		if (ft_isdigit(*str) == 0)
		{
			return (0);
		}
		str++;
	}
	return (1);
}
