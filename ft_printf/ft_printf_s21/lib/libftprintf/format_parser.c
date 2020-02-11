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



char* try_parse_flags(char* format, t_fmt* fmt, BOOL *found)
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

void	normalize_flags(t_fmt* fmt)
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


char* try_parse_type(char* format, t_fmt* fmt)
{
	if (is_valid_type(*format))
	{
		fmt->type = *format;
		return (format + 1);
	}
	return (format);
}


char* try_parse_width(char* format, t_fmt* fmt)
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
char* try_parse_precision(char* format, t_fmt* fmt)
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


char* try_parse_length(char* format, t_fmt* fmt)
{
	int	i;

	i = 0;

	if (*format != 0 && ft_contains("hlLjzt", *format))
	{
		fmt->length[i++] = *format;
		format++;
	}

	if (*format != 0 && ft_contains("hl", *format) && fmt->length[0] == *format)
	{
		fmt->length[i++] = *format;
		format++;
	}

	return (format);
}




char* try_parse_settings(char* format, t_fmt* fmt, t_list* list, int *r)
{
	char* new_format;
	BOOL	smth_parsed;

	*r = -2;
	smth_parsed = FALSE;
	new_format = format;
	format = try_parse_flags(format, fmt, &smth_parsed);
	smth_parsed = format != new_format;
	normalize_flags(fmt);
	format = try_parse_width(format, fmt);
	format = try_parse_precision(format, fmt);
	format = try_parse_length(format, fmt);
	format = try_parse_type(format, fmt);

	if (fmt->type == 0)
	{
		smth_parsed = smth_parsed
			|| fmt->precision != DEFAULT_PRECISION
			|| fmt->width != DEFAULT_WIDTH
			|| fmt->precision != DEFAULT_PRECISION
			|| *fmt->length != 0;
		if (smth_parsed)//|| fmt->precision != 0
		{
			if (*format == 0)
			{
				*r = -1;
				return (NULL);
			}
			else
			{
				add_string(list, format_to_string(*fmt));
			}
		}
		else
		{
			add_string(list, "%");
		}
	}
	else
	{
		if (fmt->flags.zero_pad
			&& fmt->width != DEFAULT_WIDTH
			//&& !fmt->flags.blank_before_positive
			&& ft_contains("diuoxX", fmt->type)
			&& fmt->precision != DEFAULT_PRECISION)
		{
			fmt->flags.zero_pad = FALSE;
		}
		add_format(list, fmt);
	}
	*r = 0;
	return (format);
}

char* try_extract_id(t_list* list, char* format, int *r)
{
	if (*format == '%')
	{
		add_string(list, "%");
		*r = 0;
		return (format + 1);
	}
	if (*format == 0)
	{
		*r = 0;
		return (format);
	}
	return (try_parse_settings(format, get_default_format(), list, r));
}