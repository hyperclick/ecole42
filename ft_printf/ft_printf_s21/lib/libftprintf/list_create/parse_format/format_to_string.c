/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_internal.h"

char *flags_to_string(t_fmt_flags f)
{
	char *str;
	int		i;

	str = malloc(sizeof(char) * 7);
	i = 0;
	str[i++] = '%';
	if (f.is_alt_form)
	{
		str[i++] = '#';
	}
	if (f.plus_before_positive)
	{
		str[i++] = '+';
	}
	if (f.blank_before_positive)
	{
		str[i++] = ' ';
	}
	if (f.adjust_left)
	{
		str[i++] = '-';
	}
	if (f.zero_pad)
	{
		str[i++] = '0';
	}
	str[i] = 0;
	return (str);
}

char *precision_to_string(int p)
{
	char *precision;
	char *tmp;

	//if (p == DEFAULT_PRECISION)
	//{
	//	precision = ft_strdup("");
	//}
	//else
	{
		tmp = ft_itoa(p);
		precision = ft_strjoin(".", tmp);
		free(tmp);
	}
	return (precision);
}

char *format_to_string(t_fmt fmt)
{
	char *flags;
	char *width;
	char *precision;
	char *r;

	flags = flags_to_string(fmt.flags);
	width = fmt.width == DEFAULT_WIDTH ? ft_strdup("") : ft_itoa(fmt.width);
	precision = fmt.precision_set ? precision_to_string(fmt.precision) : ft_strdup("");
	r = ft_strjoin2(3, flags, width, precision);
	free(flags);
	free(width);
	free(precision);
	return (r);
}
