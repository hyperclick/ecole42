/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_printf_internal.h"

t_fmt* oct_to_string(t_fmt* fmt, unsigned long long int n)
{
	if (fmt->flags.is_alt_form)
	{
		fmt->prefix = ft_strdup("0");
		if (fmt->precision_set && fmt->precision > 0)
		{
			fmt->precision--;
		}
	}
	if (n == 0)
	{
		if (fmt->flags.is_alt_form || (fmt->precision_set && fmt->precision == 0))
		{
			fmt->value = ft_strdup("");
		}
		else
		{
			fmt->value = ft_strdup("0");
		}
	}
	else
	{
		fmt->value = ft_itoa_base2(n, "01234567", FALSE);
	}
	//if (fmt->flags.is_alt_form && n != 0)
	return (fmt);
}