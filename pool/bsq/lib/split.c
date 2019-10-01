/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:57:39 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 22:57:41 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

#define LAST_STRING  NULL

BOOL	is_end_of_string_array(char *str)
{
	return (str == LAST_STRING);
}

int		get_lenght_of_string_array(char *a[])
{
	int		i;

	i = 0;
	while (!is_end_of_string_array(a[++i]))
	{
	}
	return (i);
}

void	split_impl(char *str, char *delimeters, char **r, int j)
{
	char	*tmp;
	BOOL	previous_is_space;

	j = 0;
	previous_is_space = TRUE;
	while (*str != 0)
	{
		while (contains(delimeters, *str))
		{
			++str;
			previous_is_space = TRUE;
		}
		if (*str == 0)
			break ;
		if (!contains(delimeters, *str))
		{
			if (previous_is_space == TRUE)
			{
				r[j] = malloc(sizeof(char) * ft_strlen(str));
				tmp = r[j++];
			}
			previous_is_space = FALSE;
			*tmp++ = *str++;
		}
	}
}

char	**split(char *str, int *len, char *delimeters)
{
	char	**r;

	*len = count_words(str, delimeters);
	r = malloc(sizeof(char*) * (*len + 1));
	if (*str == 0)
		return (r);
	split_impl(str, delimeters, r, 0);
	r[*len] = LAST_STRING;
	return (r);
}

int		count_not_splitted_char(char *src[], char to_split)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (!is_end_of_string_array(src[++i]))
	{
		len += ft_count_char(src[i], to_split);
	}
	return (len);
}

void	split_char_impl(char *src[], char to_split, char **dst, int i)
{
	int		j;
	char	*tmp;
	char	*str;

	j = 0;
	while (!is_end_of_string_array(src[++i]))
	{
		str = src[i];
		if (str == NULL || *str == 0)
			continue;
		while (*str != 0)
		{
			if (*str != to_split)
			{
				tmp = malloc(sizeof(char) * (ft_strlen(str) + 1));
				dst[j++] = tmp;
				while (*str != 0 && *str != to_split)
					*tmp++ = *str++;
				*tmp = 0;
				continue;
			}
			if (*str == to_split)
			{
				tmp = malloc(sizeof(char) * 2);
				dst[j++] = tmp;
				*tmp++ = *str++;
				*tmp = 0;
				continue;
			}
		}
	}
}

char	**split_char(char *src[], char to_split)
{
	int		chars_len;
	int		new_len;
	char	**dst;

	chars_len = count_not_splitted_char(src, to_split);
	if (chars_len == 0)
	{
		return (src);
	}
	new_len = get_lenght_of_string_array(src) + chars_len;
	dst = malloc(sizeof(char*) * (new_len + 1));
	split_char_impl(src, to_split, dst, -1);
	dst[new_len] = LAST_STRING;
	return (dst);
}
