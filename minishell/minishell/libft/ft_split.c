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

void		ft_free_array(void **r, int n)
{
	printf("free n = %d\n", n);
	while (n-- > 0)
	{
		//printf("free %d: '%s'\n", n, r[n]);
		free(r[n]);
		//ft_putstr("freed\n");
	}
}

int		ft_count_null_term_array(void **a)
{
	int	count;
	count = 0;
	while (*a != NULL)
	{
		a++;
		count++;
	}
	return (count);
}

void		ft_free_null_term_array(void **a)
{
	ft_free_array(a, ft_count_null_term_array(a));
}
char		**ft_split(char **r, const char *str, int count, const char *sep)
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
		{
		}
		if (*str == 0)
		{
			*dst = 0;
			continue;
		}
		while (*str != 0 && ft_contains(sep, *str) == 0)
		{
			*dst++ = *str++;
		}
		*dst = 0;
	}
	return (r);
}
