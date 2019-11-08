/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:12:27 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:12:29 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_last_index(const char *str, const char to_find)
{
	ssize_t	len;

	len = ft_strlen(str);
	while (--len >= 0)
	{
		if (str[len] == to_find)
		{
			return (len);
		}
	}
	return (-1);
}
