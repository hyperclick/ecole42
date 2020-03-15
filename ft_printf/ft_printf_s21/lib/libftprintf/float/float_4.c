/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:22:19 by plettie           #+#    #+#             */
/*   Updated: 2020/02/24 15:22:25 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

static void	ft_minus_help(t_double *s)
{
	int		l;

	l = 0;
	s->str[(s->count) - 1] = s->str[(s->count) - 1] + s->str[s->count] / 10;
	while (s->str[(s->count) - 1 - l] > '9')
	{
		++l;
		s->str[(s->count) - 1 - l] = s->str[(s->count) - 1 - l] \
				+ ((s->str[(s->count) - l] - '0') / 10);
		s->str[(s->count) - l] = (s->str[(s->count) - l] - '0') % 10 + '0';
	}
	s->str[s->count] = s->str[s->count] % 10;
}

static void	ft_plus_help(t_double *s)
{
	int		l;

	l = 0;
	s->str[(s->count) + 1] = s->str[(s->count) + 1] + s->str[s->count] / 10;
	while (s->str[(s->count) + 1 + l] > 9)
	{
		++l;
		s->str[(s->count) + 1 + l] = s->str[(s->count) + 1 + l] + (s->str[(s->count) + l] / 10);
		s->str[(s->count) + l] = s->str[(s->count) + l] % 10;
	}
	s->str[s->count] = s->str[s->count] % 10;
}

static void	ft_minus(char **buf, t_double *s, int len, int strs)
{
	int		i;
	int		j;

	j = -1;
	while (++j < len)
	{
		i = -1;
		while (++i < strs)
		{
			if (buf[i])
			{
				if (buf[i][j] == '\0')
					buf[i] = NULL;
				else
				{
					s->str[s->count] = s->str[s->count] + buf[i][j] - '0';
					if (s->str[s->count] > 9)
						ft_minus_help(s);
				}
			}
		}
		s->str[s->count] = s->str[s->count] + '0';
		++s->count;
	}
}

static void	ft_plus(char **buf, t_double *s, int len, int strs)
{
	int		i;
	int		j;

	j = -1;
	while (++j < len)
	{
		i = -1;
		while (++i < strs)
		{
			if (buf[i])
			{
				if (buf[i][j] == '\0')
					buf[i] = NULL;
				else
				{
					s->str[s->count] = s->str[s->count] + buf[i][j] - '0';
					if (s->str[s->count] > 9)
						ft_plus_help(s);
				}
			}
		}
		s->str[s->count] = s->str[s->count] + '0';
		++s->count;
	}
}

char		*ft_sum_to_str(t_double *s, char **buf, int strs, size_t len, int sign)
{
	if (!(s->str = ft_strnew(len)))
		return (NULL);
	s->count = 0;
	if (sign)
		ft_minus(buf, s, len, strs);
	else
		ft_plus(buf, s, len, strs);
	if (sign)
		while (s->str[--s->count] == '0')
			s->str[s->count] = '\0';
	return (s->str);
}
