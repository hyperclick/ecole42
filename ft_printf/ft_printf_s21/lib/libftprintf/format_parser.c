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

char *flags_to_string(t_fmt_flags f)
{
	char *str;
	int		i;

	str = malloc(sizeof(char) * 7);
	i = 0;
	str[i++] = '%';
	if (f.is_alt_form)
	{
		str[i++] = '#';
	}
	if (f.plus_before_positive)
	{
		str[i++] = '+';
	}
	if (f.blank_before_positive)
	{
		str[i++] = ' ';
	}
	if (f.adjust_left)
	{
		str[i++] = '-';
	}
	if (f.zero_pad)
	{
		str[i++] = '0';
	}
	str[i] = 0;
	return (str);
}

char *precision_to_string(int p)
{
	char *precision;
	char *tmp;

	if (p == DEFAULT_PRECISION)
	{
		precision = ft_strdup("");
	}
	else
	{
		tmp = ft_itoa(p);
		precision = ft_strjoin(".", tmp);
		free(tmp);
	}
	return (precision);
}


char *format_to_string(t_fmt fmt)
{
	char *flags;
	char *width;
	char *precision;
	char *r;

	flags = flags_to_string(fmt.flags);
	width = fmt.width == DEFAULT_WIDTH ? ft_strdup("") : ft_itoa(fmt.width);
	precision = fmt.precision_set ? precision_to_string(fmt.precision) : ft_strdup("");
	r = ft_strjoin2(3, flags, width, precision);
	free(flags);
	free(width);
	free(precision);
	return (r);
}

char *handle_empty_type(int *r, char **dst, char *format, t_fmt *fmt, BOOL	smth_parsed)
{
	if ((fmt->width > 1 || (fmt->precision_set && fmt->precision < 0)) && *format != 0)//!fmt->flags.adjust_left)
	{

		int len = fmt->width != 0 ? fmt->width : fmt->precision;
		if (len < 0)
		{
			len = -len;
		}
		char *pads = ft_str_repeat(fmt->flags.zero_pad && fmt->width > 1 ? "0" : " ", len - 1);
		if (fmt->flags.adjust_left || (fmt->precision_set && fmt->precision < 0))
		{
			*dst = ft_prepend_and_free(*format, pads);
			format++;
		}
		else
		{
			*dst = pads;
		}
	}
	else
	{
		*dst = ft_strdup("");
	}
	*r = 0;
	return (format);
}

void	handle_not_empty_type(int *r, t_fmt *fmt)
{
	if (fmt->flags.zero_pad
		&& fmt->width != DEFAULT_WIDTH
		&& !fmt->flags.blank_before_positive
		&& ft_contains("diuoxX", fmt->type)
		&& fmt->precision_set)
	{
		fmt->flags.zero_pad = FALSE;
	}
	*r = 0;
}

char *handle_parsed(char *format, t_fmt *fmt, t_list *list, int *r, BOOL	smth_parsed)
{
	char *str;

	*r = -3;
	if (fmt->type == 0)
	{
		format = handle_empty_type(r, &str, format, fmt, smth_parsed);
		if (*r == 0)
		{
			add_string(list, str);
			free_format(fmt);
		}
	}
	else
	{
		handle_not_empty_type(r, fmt);
		if (*r == 0)
		{
			add_format(list, fmt);
		}
	}
	return (format);
}

char *try_parse_settings(char *format, t_fmt *fmt, t_list *list, int *r)
{
	char *new_format;
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

	//%-w.-p || %w.-p
	if (fmt->width != DEFAULT_WIDTH && fmt->precision < 0 && fmt->precision_set)
	{
		fmt->width = DEFAULT_WIDTH;
	}
	format = handle_parsed(format, fmt, list, r, smth_parsed);
	return (format);
}

char *try_extract_id(t_list *list, char *format, int *r)
{
	if (*format == '%')
	{
		add_string(list, ft_strdup("%"));
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