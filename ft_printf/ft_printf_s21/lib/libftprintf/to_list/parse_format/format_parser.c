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

#include "../../ft_printf_internal.h"
#include <stdio.h>

char *try_parse_flags(char *format, t_fmt *fmt, BOOL *found)
{
	*found = FALSE;
	while (*format != 0)
	{
		if (*format == '#')
		{
			fmt->flags.is_alt_form = TRUE;
			*found = TRUE;
		}
		else if (*format == '0')
		{
			fmt->flags.zero_pad = TRUE;
			*found = TRUE;
		}
		else if (*format == '-')
		{
			fmt->flags.adjust_left = TRUE;
			*found = TRUE;
		}
		else if (*format == ' ')
		{
			fmt->flags.blank_before_positive = TRUE;
			*found = TRUE;
		}
		else if (*format == '+')
		{
			fmt->flags.plus_before_positive = TRUE;
			*found = TRUE;
		}
		else
		{
			return (format);
		}
		format++;
	}
	return (format);
}

char *try_parse_type(char *format, t_fmt *fmt)
{
	if (is_valid_type(*format))
	{
		fmt->type = *format;
		printf("[%s] format + 1 address = %p\n", __FUNCTION__, format + 1);
		printf("format + 1 = '%s'\n", format + 1);
		return (format + 1);
	}
	return (format);
}

char *try_parse_width(char *format, t_fmt *fmt)
{
	if (*format != '0')
	{
		while (*format != 0 && ft_isdigit(*format))
		{
			fmt->width = fmt->width * 10 + *format - '0';
			format++;
		}
	}
	return (format);
}

char *try_parse_precision(char *format, t_fmt *fmt)
{
#ifdef MAC_OS

	BOOL	is_negative;

	is_negative = FALSE;
#endif // MAC_OS

	if (*format == '.')
	{
		fmt->precision_set = TRUE;
		fmt->precision = 0;
		format++;
		if (*format == 0)
		{
			return (format);
		}
#ifdef MAC_OS
		if (*format == '-')
		{
			is_negative = TRUE;
			format++;
		}
#endif
		if (*format == 0)
		{
			//			return (format - 1);
		}
		while (*format != 0 && ft_isdigit(*format))
		{
			fmt->precision = fmt->precision * 10 + *format - '0';
			format++;
		}
#ifdef MAC_OS
		if (is_negative)
		{
			fmt->precision = -fmt->precision;
		}
#endif
	}
	return (format);
}

char *try_parse_length(char *format, t_fmt *fmt)
{
	int	i;

	i = 0;

	while (*format != 0 && ft_contains("hlLjzt", *format))
	{
		fmt->length[i] = *format;
		if (i != 1)
		{
			++i;
		}
		format++;
	}

	return (format);
}
