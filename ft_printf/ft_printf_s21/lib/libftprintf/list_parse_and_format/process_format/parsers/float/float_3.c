/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:22:10 by plettie           #+#    #+#             */
/*   Updated: 2020/02/24 15:22:13 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

void		ft_bits(unsigned char num, unsigned char *str)
{
	int oct;
	int div;
	int j;

	j = 0;
	div = 128;
	oct = num;
	while (div != 0 && j < 8)
	{
		if (div <= oct)
		{
			str[j++] = '1';
			oct = oct % div;
		}
		else
			str[j++] = '0';
		div = div / 2;
	}
}

static int		ft_f_man(char **s, int i)
{
	while (!s[i] && i < 64)
		++i;
	return (i);
}

char		*ft_low(t_double *floats, char **s)
{
	int		i;
	int		len;
	char	*tmp1;
	char	*tmp2;

	i = ft_f_man(s, 0);
	len = ft_strlen(s[i]);
	tmp2 = NULL;
	if (!(tmp1 = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	tmp1[0] = '0';
	tmp1[1] = '\0';
	floats->length = 1;
	while (++i < 64)
		if (s[i])
			len += 2;
	if (len)
	{
		if (!(tmp2 = ft_sum_to_str(floats, s, 64, len, 1)))
			return (ft_frees(s, 65));
		ft_change_prec(floats, tmp1, tmp2, len);
	}
	return (ft_final_str_from_2(floats, tmp1, tmp2));
}

char		*ft_more(t_double *floats, char **s)
{
	int		i;
	char	*tmp1;
	char	*tmp2;

	i = ft_f_man(s, 0);
	if (!(tmp1 = ft_sum_to_str(floats, s, 64, ft_strlen(s[i]) + 1, 0)))
		return (ft_frees(s, 65));
	i = 0;
	tmp2 = NULL;
	if (floats->prec)
	{
		if (!(tmp2 = (char *)malloc(sizeof(char) * (floats->prec + 1))))
			return (ft_free(tmp1, NULL));
		tmp2[floats->prec] = '\0';
		while (i < floats->prec)
			tmp2[i++] = '0';
	}
	while (tmp1[floats->length - 1] == '0')
		tmp1[--floats->length] = '\0';
	ft_strrev(tmp1);
	if (floats->prec)
		return (ft_final_str_from_2(floats, tmp1, tmp2));
	return (tmp1);
}

char		*ft_between(t_double *floats, char **s, int exp)
{
	int		i;
	int		len;
	char	*tmp1;
	char	*tmp2;

	if (!(tmp1 = ft_sum_to_str(floats, s, exp + 1, ft_strlen(s[ft_f_man(s, 0)]) + 1, 0)))
		return (NULL);
	floats->length = ft_strlen(tmp1);
	i = ft_f_man(s, exp + 1);
	len = ft_strlen(s[i]);
	tmp2 = NULL;
	while (++i < 64)
		if (s[i])
			len += 2;
	if (len)
	{
		if (!(tmp2 = ft_sum_to_str(floats, &s[exp + 1], 64 - (exp + 1), len, 1)))
			return (ft_free(tmp1, NULL));
		ft_change_prec(floats, tmp1, tmp2, len);
	}
	while (tmp1[floats->length - 1] == '0')
		tmp1[--floats->length] = '\0';
	ft_strrev(tmp1);
	return (ft_final_str_from_2(floats, tmp1, tmp2));
}
