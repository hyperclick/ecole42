/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_printf_internal.h"

t_fmt* hex_to_string2(t_fmt* fmt, unsigned long long int p, BOOL is_upper_case, BOOL add_prefix)
{

	if (fmt->type != 'p' && p == 0 && fmt->precision_set && fmt->precision == 0)
	{
		fmt->value = ft_strdup("");
		return (fmt);
	}
	fmt->value = ft_itoa_base2(p, is_upper_case ? "0123456789ABCDEF" : "0123456789abcdef", FALSE);
	if (add_prefix)
	{
		fmt->prefix = ft_strdup(is_upper_case ? "0X" : "0x");
	}
	return (fmt);
}

t_fmt* hex_to_string(t_fmt* fmt, unsigned long long int p, BOOL is_upper_case)
{
	return (hex_to_string2(fmt, p, is_upper_case, fmt->flags.is_alt_form && p != 0));
}

t_fmt* little_hex_to_string(t_fmt* fmt, unsigned long long int p)
{
	return(hex_to_string(fmt, p, FALSE));
}

t_fmt* big_hex_to_string(t_fmt* fmt, unsigned long long int p)
{
	return(hex_to_string(fmt, p, TRUE));
}

t_fmt* pointer_to_string(void* p, t_fmt* fmt)
{
	fmt->flags.plus_before_positive = FALSE;
	if (p == NULL)
	{
		p = 0;
	}

	hex_to_string2(fmt, (unsigned long long int)p, FALSE, TRUE);


	return (fmt);
}
