/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:36:09 by darugula          #+#    #+#             */
/*   Updated: 2019/09/10 10:36:23 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *str, char c)
{
	char	delimeters[2];
	char	**r;
	int		count;

	if (str == NULL)
	{
		return (NULL);
	}
	delimeters[0] = c;
	delimeters[1] = 0;
	count = ft_count_words(str, delimeters);
	r = (char**)malloc(sizeof(char*) * (count + 1));
	if (r != NULL)
	{
		r[count] = NULL;
		if (ft_split(r, str, count, delimeters) == NULL)
		{
			free(r);
			r = NULL;
		}
	}
	return (r);
}
