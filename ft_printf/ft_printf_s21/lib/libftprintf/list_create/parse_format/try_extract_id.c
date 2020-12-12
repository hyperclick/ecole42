/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_extract_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf_internal.h"

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
		*r = -1;
		return (format);
	}
	return (try_parse_settings(format, get_default_format(), list, r));
}