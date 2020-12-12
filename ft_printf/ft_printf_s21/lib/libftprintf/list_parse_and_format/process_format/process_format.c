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


BOOL	is_null_pointer(t_fmt *fmt)
{
	return (fmt->type == 's' && (ft_strequ(fmt->value, "(nil)") || ft_strequ(fmt->value, "(null)")));
}

void	recalc_size(t_fmt *fmt)
{
	if (is_zero_char(fmt))
	{
		return;
	}
	fmt->size = ft_strlen(fmt->value);
	if (fmt->pad_right != NULL)
	{
		fmt->size += ft_strlen(fmt->pad_right);
	}
	fmt->size += ft_strlen(fmt->prefix);
	if (fmt->pad_left != NULL)
	{
		fmt->size += ft_strlen(fmt->pad_left);
	}
}

BOOL	need_exit(t_fmt *fmt)
{
	return (
		(	!(fmt->length[0] == 'l' && fmt->length[1] == 'l') && fmt->type == 's' && ft_contains("l", *fmt->length) && *fmt->value != 0 && !is_null_pointer(fmt) && fmt->precision >= 0 )
		||
		(fmt->size == -1)
		//(!(fmt->length[0] == 'l' && fmt->length[1] == 'l') && fmt->type == 'c' && ft_contains("l", *fmt->length) && *fmt->value < 0)
		);
}

void	process_string(t_fmt *fmt)
{
	if (fmt->prefix == NULL)
	{
		fmt->prefix = ft_strdup("");
	}
	if (fmt->size == -1)
	{
//		fmt->size = -1;
		free(fmt->value);
		fmt->value = ft_strdup("should not see this");
		fmt->pad_left = ft_strdup("should not see this");
		fmt->pad_right = ft_strdup("should not see this");
		return;
	}
	process_sign(fmt);
	recalc_size(fmt);
	process_blank(fmt);
	recalc_size(fmt);
	process_precision(fmt);
	recalc_size(fmt);
	recalc_size(fmt);
	process_width(fmt);
	recalc_size(fmt);
	if (fmt->pad_left == NULL)
	{
		fmt->pad_left = ft_strdup("");
	}
	if (fmt->pad_right == NULL)
	{
		fmt->pad_right = ft_strdup("");
	}
}
