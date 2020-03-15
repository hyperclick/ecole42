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

char	*get_pad(t_fmt *fmt)
{
	if (fmt->flags.zero_pad)
	{
		if (fmt->type == 'c' || fmt->type == 's' || !fmt->precision_set )
		{
			return ("0");
		}
	}
	return (" ");
}

void	process_width(t_fmt *fmt)
{
	char *pads;

	if (fmt->width < fmt->size)
	{
		return;
	}
	pads = ft_str_repeat(get_pad(fmt), fmt->width - fmt->size);
	if (is_zero_char(fmt))
	{
		fmt->size += ft_strlen(pads);
	}

	if (fmt->flags.adjust_left)
	{
		fmt->pad_right = pads;
	}
	else
	{
		if (pads[0] != '0' || is_zero_char(fmt))
		{
			fmt->prefix = ft_str_prepend_and_free(pads, fmt->prefix);
		}
		else
		{
			fmt->value = ft_str_prepend_and_free(pads, fmt->value);
		}
		free(pads);
	}
}
