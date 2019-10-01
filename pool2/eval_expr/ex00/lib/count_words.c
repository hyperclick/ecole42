/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:42:56 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 22:42:59 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include <limits.h>

const int	g_last_int = INT_MIN;

int			count_words(char *str, char *delimeters)
{
	int		len;
	BOOL	previous_is_space;

	len = 0;
	if (*str == 0)
		return (0);
	previous_is_space = TRUE;
	while (*str != 0)
	{
		while (contains(delimeters, *str))
		{
			++str;
			previous_is_space = TRUE;
		}
		if (*str == 0)
			return (len);
		if (!contains(delimeters, *str))
		{
			if (previous_is_space == TRUE)
				++len;
			previous_is_space = FALSE;
			++str;
		}
	}
	return (len);
}
