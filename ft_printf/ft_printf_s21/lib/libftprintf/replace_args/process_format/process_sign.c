/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asserts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf_internal.h"

void	process_sign(t_fmt *fmt)
{
	if ((is_signed_number(fmt->type) || fmt->type == 'p') && fmt->flags.plus_before_positive)
	{
		if (fmt->prefix[0] != '-')
		{
			if (fmt->precision < 0)
			{
				fmt->value = ft_str_prepend_and_free("+", fmt->value);
			}
			else
			{
				fmt->prefix = ft_str_prepend_and_free("+", fmt->prefix);
			}
		}
	}
}