/*_**************************************************************************_*/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:10:53 by darugula          #+#    #+#             */
/*   Updated: 2019/09/10 11:10:55 by darugula         ###   ########.fr       */
/*                                                                            */
/*_**************************************************************************_*/

#include "libft.h"

int		ft_count_words(const char *str, const char whitespaces[])
{
	int	count;
	int	prev_is_space;

	count = 0;
	prev_is_space = 1;
	while (*str != 0)
	{
		if (ft_contains(whitespaces, *str) == 0)
		{
			if (prev_is_space == 1)
			{
				++count;
			}
			prev_is_space = 0;
		}
		if (ft_contains(whitespaces, *str) == 1)
		{
			prev_is_space = 1;
		}
		++str;
		continue;
	}
	return (count);
}
