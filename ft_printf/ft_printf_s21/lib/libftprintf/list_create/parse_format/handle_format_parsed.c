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

char *handle_empty_type(int *r, char **dst, char *format, t_fmt *fmt, BOOL	smth_parsed)
{
	*r = 0;
	//if ((fmt->width > 1 || (fmt->precision_set && fmt->precision < 0)) && *format != 0)//!fmt->flags.adjust_left)
	//{

	//	int len = fmt->width != 0 ? fmt->width : fmt->precision;
	//	if (len < 0)
	//	{
	//		len = -len;
	//	}
	//	char *pads = ft_str_repeat(fmt->flags.zero_pad && fmt->width > 1 ? "0" : " ", len - 1);
	//	if (fmt->flags.adjust_left || (fmt->precision_set && fmt->precision < 0))
	//	{
	//		*dst = ft_prepend_and_free(*format, pads);
	//		format++;
	//	}
	//	else
	//	{
	//		*dst = pads;
	//	}
	//}
	//else if (*format != 0 && fmt->precision_set && fmt->precision == 0)
	//if (fmt->width > 0)
	//{
	//	*r = -1;
	//	*dst = ft_strdup("");
	//}
	//else if ((*format != 0 && fmt->precision_set))// || fmt->width > 0)
	if ((*format != 0))// || fmt->width > 0)
	{
		//*dst = fmt->flags.blank_before_positive ? ft_strdup("% .0") : ft_strdup("%.0");
		*dst = format_to_string(*fmt);
	}
	else
	{
		*dst = ft_strdup("%");
		if (*format == 0)
		{
			*r = -1;
		}
	}
	return (format);
}

void	handle_not_empty_type(int *r, t_fmt *fmt)
{
	//if (fmt->type=='s' && fmt->length[0] == 'l')
	//{
	//	*r = -1;
	//	return;
	//}
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

char *handle_parsed(char *format, t_fmt *fmt, t_list *list, int *r, BOOL smth_parsed)
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
