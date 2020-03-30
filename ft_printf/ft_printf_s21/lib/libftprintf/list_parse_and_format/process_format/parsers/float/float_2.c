/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:22:01 by plettie           #+#    #+#             */
/*   Updated: 2020/02/24 15:22:05 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

static char	*ft_negative(char *res, int degree)
{
	char	*tmp;
	int		i;
	int		j;

	if (!(tmp = ft_strnew(degree)))
		return (ft_free(tmp, NULL));
	i = degree;
	j = ft_strlen(res);
	while (--i >= j)
		tmp[degree - i - 1] = '0';
	while (i >= 0)
	{
		tmp[degree - i - 1] = res[i];
		i--;
	}
	free(res);
	return (tmp);
}

char	*ft_final_str(const unsigned char *bin_deg, char *res, int degree,
							 int sign)
{
	int		i;
	char	*b;

	i = 0;
	if (sign < 0)
		b = "5";
	else
		b = "2";
	while (bin_deg[i] != '1')
		++i;
	while (i < 16)
	{
		if (bin_deg[i++] == '1')
			res = ft_strjoin(ft_strjoin(res, res), b);
		else
			res = ft_strjoin(res, res);
		if (res == NULL)
			return (NULL);
	}
	if (sign < 0)
		res = ft_negative(res, degree);
	return (res);
}

char		*ft_final_str_from_2(t_double *floats, char *tmp1, char *tmp2)
{
	char	*res;
	int		i;

	i = floats->length;
	if (floats->prec)
		floats->length = floats->length + 1 + floats->prec;
	if (!(res = (char *)malloc(sizeof(char) * (floats->length + 1))))
		return (ft_free(tmp1, tmp2));
	res[floats->length] = '\0';
	res = ft_strcpy(res, tmp1);
	if (floats->prec)
	{
		res[i] = '.';
		res[i + 1] = '\0';
		if (tmp2)
			res = ft_strncat(res, tmp2, floats->prec);
		while (res[i])
			++i;
		while (i < floats->length)
			res[i++] = '0';
	}
	ft_free(tmp1, tmp2);
	return (res);
}

static void			ft_change_help(int *i, char *tmp2)
{
	if (--(*i) >= 0)
	{
		tmp2[*i] += 1;
		while (tmp2[*i] > '9' && (*i) >= 0)
		{
			tmp2[*i] = '0';
			if (--(*i) >= 0)
				tmp2[*i] += 1;
		}
	}
}

void				ft_change_prec(t_double *floats, char *tmp1, char *tmp2, int len)
{
	int	i;

	i = floats->prec;
	while (tmp2[i] && i >= floats->prec && i <= len)
	{
		if (tmp2[i] < '5')
			break ;
		else if (tmp2[i] >= '5')
			ft_change_help(&i, tmp2);
	}
	if (i++ < 0)
	{
		tmp1[i] += 1;
		while (tmp1[i] > '9')
		{
			tmp1[i] = '0';
			tmp1[++i] += 1;
		}
	}
}
