/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:59:02 by darugula          #+#    #+#             */
/*   Updated: 2019/09/10 11:59:04 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char **r, const char *str, int count, const char *sep)
{
	int		i;
	char	*dst;

	i = 0;
	while (i < count)
	{
		dst = malloc((ft_strlen(str) + 1) * sizeof(char));
		if (dst == NULL)
		{
			ft_free_array((void**)r, i);
			return (NULL);
		}
		r[i++] = dst;
		while (*str != 0 && ft_contains(sep, *str) == 1 && ++str)
			;
		if (*str == 0)
		{
			*dst = 0;
			continue;
		}
		while (*str != 0 && ft_contains(sep, *str) == 0)
			*dst++ = *str++;
		*dst = 0;
	}
	return (r);
}

char	**ft_split2(const char *str, int count, const char *sep)
{
	char	**r;

	r = (char**)malloc(sizeof(char**) * (count + 1));
	if (r == NULL)
	{
		ft_e_putstr("ft_split2 malloc failed\n");
		exit(1);
	}
	r[count] = NULL;
	if (ft_split(r, str, count, sep) == NULL)
	{
		ft_e_putstr("ft_split2 malloc2 failed\n");
		free(r);
		exit(1);
	}
	return (r);
}

char	**ft_split3(const char *str, const char *sep)
{
	return (ft_split2(str, ft_count_words(str, sep), sep));
}
