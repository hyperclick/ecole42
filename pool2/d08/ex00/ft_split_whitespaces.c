/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:43:49 by darugula          #+#    #+#             */
/*   Updated: 2019/07/11 18:43:52 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i++] != 0)
	{
	}
	return (i - 1);
}

int		contains(const char *str, char to_find)
{
	while (*str != 0)
	{
		if (*str == to_find)
		{
			return (1);
		}
		str++;
	}
	return (0);
}

int		count_words(char *str, const char whitespaces[])
{
	int	count;
	int	prev_is_space;

	count = 0;
	prev_is_space = 1;
	while (*str != 0)
	{
		if (contains(whitespaces, *str) == 0)
		{
			if (prev_is_space == 1)
			{
				++count;
			}
			prev_is_space = 0;
		}
		if (contains(whitespaces, *str) == 1)
		{
			prev_is_space = 1;
		}
		++str;
		continue;
	}
	return (count);
}

char	**split(char **r, char *str, int count, const char whitespaces[])
{
	int		i;
	char	*dst;

	i = 0;
	while (i < count)
	{
		dst = malloc(ft_strlen(str) * sizeof(char));
		r[i++] = dst;
		while (*str != 0 && contains(whitespaces, *str) == 1 && ++str)
		{
		}
		if (*str == 0)
		{
			*dst = 0;
			continue;
		}
		while (*str != 0 && contains(whitespaces, *str) == 0)
		{
			*dst = *str;
			++dst;
			++str;
		}
		*dst = 0;
	}
	return (r);
}

char	**ft_split_whitespaces(char *str)
{
	const char	whitespaces[] = "\t\n ";
	char		**r;
	int			count;
	char		*buffer;

	count = count_words(str, whitespaces);
	++count;
	r = (char**)malloc(sizeof(char**) * count);
	buffer = (char*)malloc(sizeof(char*) * 1);
	*buffer = 0;
	r[count - 1] = buffer;
	split(r, str, count - 1, whitespaces);
	return (r);
}
