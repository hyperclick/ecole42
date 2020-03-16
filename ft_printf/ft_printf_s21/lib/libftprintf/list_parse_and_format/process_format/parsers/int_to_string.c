/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_printf_internal.h"

t_fmt	*int_to_string(t_fmt *fmt, long long int n)
{
	if (n == 0 && fmt->precision_set && fmt->precision == 0)
	{
		fmt->value = ft_strdup("");
		return (fmt);
	}
	unsigned long int	u;

	u = n;
	if (n < 0)
	{
		fmt->prefix = ft_strdup("-");
		u = -(unsigned long int)n;
	}
	fmt->value = ft_uitoa(u);
	return (fmt);
}

t_fmt	*uint_to_string(t_fmt *fmt, unsigned long long int n)
{
	if (n == 0 && fmt->precision_set && fmt->precision == 0)
	{
		fmt->value = ft_strdup("");
		return (fmt);
	}
	fmt->value = ft_uitoa(n);
	return (fmt);
}