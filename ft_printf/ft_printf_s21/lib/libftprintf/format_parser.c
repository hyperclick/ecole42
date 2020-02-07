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


char *try_parse_flags(char *format, t_fmt *fmt)
{
	while (*format != 0)
	{
		if (*format == '#')
		{
			fmt->flags.is_alt_form = TRUE;
		}
		else if (*format == '0')
		{
			fmt->flags.zero_pad = TRUE;
		}
		else if (*format == '-')
		{
			fmt->flags.adjust_left = TRUE;
		}
		else if (*format == ' ')
		{
			fmt->flags.blank_before_positive = TRUE;
		}
		else if (*format == '+')
		{
			fmt->flags.plus_before_positive = TRUE;
		}
		else
		{
			return (format);
		}
		format++;
	}
	return (format);
}

void	normalize_flags(t_fmt *fmt)
{
	if (fmt->flags.adjust_left && fmt->flags.zero_pad)
	{
		fmt->flags.zero_pad = FALSE;
	}

	if (fmt->flags.plus_before_positive && fmt->flags.blank_before_positive)
	{
		fmt->flags.blank_before_positive = FALSE;
	}
}


char *try_parse_type(char *format, t_fmt *fmt)
{
	if (is_valid_type(*format))
	{
		fmt->type = *format;
		return (format + 1);
	}
	return (format);
}


char *try_parse_width(char *format, t_fmt *fmt)
{
	//BOOL	is_negative;

	//is_negative = FALSE;
	if (*format != '0')
	{
		//if (*format == '-')
		//{
		//	is_negative = TRUE;
		//	format++;
		//}
		while (*format != 0 && ft_isdigit(*format))
		{
			fmt->width = fmt->width * 10 + *format - '0';
			format++;
		}
		//if (fmt->flags.adjust_left)
		//{
		//	fmt->width = -fmt->width;
		//	//fmt->flags.adjust_left = FALSE;
		//}
	}
	return (format);
}
char *try_parse_precision(char *format, t_fmt *fmt)
{
	BOOL	is_negative;

	is_negative = FALSE;
	if (*format == '.')
	{
		fmt->precision = 0;
		format++;
		if (*format == 0)
		{
			return (format);
		}
		if (*format == '-')
		{
			is_negative = TRUE;
			format++;
		}
		if (*format == 0)
		{
			return (format - 1);
		}
		while (*format != 0 && ft_isdigit(*format))
		{
			fmt->precision = fmt->precision * 10 + *format - '0';
			format++;
		}
		if (is_negative)
		{
			fmt->precision = -fmt->precision;
		}
	}
	return (format);
}

