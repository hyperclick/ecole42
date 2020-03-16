/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:21:01 by plettie           #+#    #+#             */
/*   Updated: 2020/02/24 15:21:31 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

char 	*ft_free(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (NULL);
}

char	*ft_frees(char **obj, int strs)
{
	while (--strs >= 0)
		if (obj && obj[strs])
			free(obj[strs]);
	free(obj);
	return (NULL);
}

char		*ft_do_union(int degree)
{
	union u_bin		deg;
	unsigned char	bin_deg[16];
	int				i;
	int				j;

	deg.i = degree;
	i = 2;
	j = -8;
	if (degree < 0)
		deg.i = (deg.i ^ 0xffffffff) + 1;
	while (--i > -1)
		ft_bits(deg.byte[i], &bin_deg[j += 8]);
	return (ft_final_str(bin_deg, "1", deg.i, degree));
}

static char	*ft_max_min(t_double *count)
{
	char	*buf;

	buf = NULL;
	if (count->bits.m == 0)
		count->bits.e = 0;
	else if (count->bits.e == 32767 && count->num != count->num)
		buf = ft_strdup("nan");
	else if (count->bits.m == 0x8000000000000000 && count->bits.e == 32767)
		buf = ft_strdup("inf");
	return (buf);
}

char			*ft_do_str(t_double *floats, int exp, const unsigned char *man)
{
	int		i;
	char	**s;
	char	*res;

	i = -1;
	res = NULL;
	if (!(s = (char **)malloc(sizeof(char *) * 65)))
		return (NULL);
	while (++i < 65)
		s[i] = NULL;
	while (--i >= 0)
		if (man[i] == '1')
			if (!(s[i] = ft_do_union(exp - i)))
				return (ft_frees(s, 65));
	if (exp >= 0 && exp <= 63)
		res = ft_between(floats, s, exp);
	else if (exp > 63)
		res = ft_more(floats, s);
	else if (exp < 0)
		res = ft_low(floats, s);
	if (!res)
		return (ft_frees(s, 65));
	return (res);
}

static char	*ft_printf_f(t_double *count, long double num)
{
	char			*buf;
	int				exp;
	unsigned char	man[65];
	int				i;

	i = 8;
	buf = NULL;
	if (count->prec < 0)
		count->prec = 6;
	count->num = num;
	count->prec = count->length;
	buf = ft_max_min(count);
	exp = count->bits.e - 16383;
	man[64] = '\0';
	while (--i >= 0)
		ft_bits(count->byte[i], &man[64 - 8 * (i + 1)]);
	if (!buf)
		if (!(buf = ft_do_str(count, exp, man)))
			exit(0);
	return (buf);
}
