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

BOOL	is_valid_length(t_fmt *fmt)
{
	return (fmt->length[0] == 0 || ft_strequ(fmt->length, "ll") || ft_strequ(fmt->length, "hh") || ft_strequ(fmt->length, "l") || ft_strequ(fmt->length, "h") || ft_strequ(fmt->length, "j") || ft_strequ(fmt->length, "t") || ft_strequ(fmt->length, "z") || ft_strequ(fmt->length, "L"));
}

BOOL	is_zero_char(t_fmt *fmt)
{
	return (fmt->type == 'c' && fmt->value[0] == 0);
}

char *append_to_zero(const char *append)
{
	char *dst;
	int		len;

	len = ft_strlen(append) + 1;

	dst = (char *)malloc(len + 1);
	dst[len] = 0;
	dst[0] = 0;
	ft_strcpy(dst + 1, append);
	return (dst);
}

void	process_precision(t_fmt *fmt)
{
	int	abs_precision;

	if (!fmt->precision_set || (fmt->type == 'c' && fmt->precision >= 0))
	{
		return;
	}
	if (fmt->type == 'c' && /*fmt->precision < 0 &&*/ !is_valid_length(fmt))
	{
		return;
	}
	abs_precision = fmt->precision < 0 ? -fmt->precision : fmt->precision;
	if (fmt->precision < 0 && fmt->type == 's')// || !is_int_number(fmt->type))
	{
		free(fmt->value);
		fmt->value = ft_str_repeat(" ", -fmt->precision);
		return;
	}
	if (fmt->precision == 0 && ft_strequ(fmt->value, "0"))
	{
		if (fmt->type == 'p')//if (fmt->flags.is_alt_form)
		{
			free(fmt->value);
			fmt->value = ft_strdup("");
		}
		return;
	}
	if (fmt->precision <0 && fmt->precision > -3 && ft_strequ(fmt->value, "0") && (fmt->type == 'p'))
	{
		free(fmt->value);
		fmt->value = ft_strdup("");
		return;
	}

	int	diff;
	char *tmp;

	diff = (fmt->precision < 0 && ft_strequ(fmt->prefix, " ") ? fmt->size : ft_strlen(fmt->value)) - abs_precision;
	if (fmt->type == 'o' && *fmt->prefix == '0' && fmt->precision <= 0)
	{
		diff++;
	}
	if (diff > 0 && fmt->type == 's')
	{
		tmp = fmt->value;

		fmt->value = ft_strsub(fmt->value, 0, fmt->precision);
		free(tmp);
	}
	else if (diff < 0 && fmt->type != 's')
	{
		char *pads;
		pads = NULL;
		if (fmt->precision < 0)
		{
			if (*fmt->prefix == '-')
			{
				diff++;
			}
			if (ft_strequ(fmt->value, "0") || ft_strequ(fmt->value, "+0"))
			{
				diff--;
				free(fmt->value);
				fmt->value = is_signed_number(fmt->type) && fmt->flags.plus_before_positive ? ft_strdup("+") : ft_strdup("");
			}
			if (ft_strequ(fmt->prefix, "0x") || ft_strequ(fmt->prefix, "0X"))
			{
				diff += ft_strlen(fmt->prefix);
			}
			if (diff < 0)
			{
				pads = ft_str_repeat(" ", -diff);
				tmp = fmt->value;
				if (is_zero_char(fmt))
				{
					fmt->value = append_to_zero(pads + 1);
					fmt->size = -diff;
				}
				else
				{
					fmt->value = ft_strjoin(fmt->value, pads);
				}
				free(tmp);

			}
		}
		else
		{
			pads = ft_str_repeat("0", -diff);
			fmt->value = ft_str_prepend_and_free(pads, fmt->value);
		}
		if (pads != NULL)
		{
			free(pads);
		}
	}
}