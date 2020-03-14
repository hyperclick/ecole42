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

#include "ft_printf_internal.h"

BOOL is_null_pointer(t_fmt *fmt)
{
	return (fmt->type == 's' && (ft_strequ(fmt->value, "(nil)") || ft_strequ(fmt->value, "(null)")));
}

void	process_sign1(t_fmt *fmt)
{
	if ((is_signed_number(fmt->type) || fmt->type == 'p') && fmt->flags.plus_before_positive)
	{
		if (fmt->prefix[0] != '-')
		{
			fmt->prefix = ft_str_prepend_and_free("+", fmt->prefix);
		}
	}
}
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

char *ft_str_prepend_and_free(const char *prefix, char *str)
{
	char *tmp;

	tmp = str;
	str = ft_strjoin(prefix, str);
	free(tmp);
	return (str);
}

char *ft_prepend_and_free(const char prefix, char *str)
{
	char tmp[] = " ";

	*tmp = prefix;
	return (ft_str_prepend_and_free(tmp, str));
}

void	process_blank(t_fmt *fmt)
{
	if (ft_contains("idaAeEfFgG", fmt->type)
		&& fmt->flags.blank_before_positive
		&& !fmt->flags.plus_before_positive)
	{
		if (fmt->prefix[0] != '-')
		{
			fmt->prefix = ft_str_prepend_and_free(" ", fmt->prefix);
		}
	}
}

char *get_pad(t_fmt *fmt)
{
	if (fmt->flags.zero_pad)
	{
		if (fmt->type == 'c' || !fmt->precision_set )
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
		//		pads = fmt->value;
		//		fmt->value = ft_strsub(fmt->value);
	}
	pads = ft_str_repeat(get_pad(fmt), fmt->width - fmt->size);
	//fmt->size = ft_strlen(pads) + fmt->size;
	if (is_zero_char(fmt))
	{
		fmt->size += ft_strlen(pads);
	}

	if (fmt->flags.adjust_left)
	{
		fmt->pad_right = pads;
		//char* tmp = fmt->value;
		//fmt->value = malloc(sizeof(char) * (ft_strlen(pads) + fmt->size + 1));
		//ft_strcpy(fmt->value, );
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
	char *pads;
	char *tmp;

	diff = ft_strlen(fmt->value) - abs_precision;
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
		else
		{
			pads = ft_str_repeat("0", -diff);
			fmt->value = ft_str_prepend_and_free(pads, fmt->value);
		}
		free(pads);
	}
}


BOOL	need_exit(t_fmt *fmt)
{
	return (
		(	!(fmt->length[0] == 'l' && fmt->length[1] == 'l') && fmt->type == 's' && ft_contains("l", *fmt->length) && *fmt->value != 0 && !is_null_pointer(fmt) && fmt->precision >= 0 )
		|| 
		(	!(fmt->length[0] == 'l' && fmt->length[1] == 'l') && fmt->type == 'c' && ft_contains("l", *fmt->length) && *fmt->value < 0	)
		);
}

void	process_string(t_fmt *fmt)
{
	if (fmt->prefix == NULL)
	{
		fmt->prefix = ft_strdup("");
	}
	if (need_exit(fmt))
	{
		fmt->size = -1;
		fmt->value = ft_strdup("should not see this");
		fmt->pad_left = ft_strdup("");
		fmt->pad_right = ft_strdup("");
		return;
	}
	process_sign(fmt);
	recalc_size(fmt);
	process_precision(fmt);
	recalc_size(fmt);
	//process_sign1(fmt);
	recalc_size(fmt);
	process_blank(fmt);
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

/*
char *process_char(t_fmt *fmt)
{
	fmt->value = fill_char(va_arg(args_list, int));
	fmt->size = 1;
	process_width(fmt);
	//if (c == 0)
	//{
	//	*size = *size + 1;
	//}
	return (NULL);
}*/

int	fill_arg(t_fmt *fmt, va_list args_list)
{
	if (fmt->type == 'c')
	{
		parse_c(fmt, args_list);
	}
	else if (fmt->type == 's')
	{
		process_string(pchar_to_string(fmt, va_arg(args_list, char *)));
	}
	else if (fmt->type == 'd' || fmt->type == 'i')
	{
		parse_d(fmt, args_list);
	}
	else if (ft_contains("uoxX", fmt->type))
	{
		parse_u(fmt, args_list);
	}
	else if (fmt->type == 'p')
	{
		process_string(pointer_to_string(va_arg(args_list, void *), fmt));
	}
	else
	{
		ft_e_putstr("unexpected format: ");
		ft_putchar_fd(fmt->type, STDERR_FILENO);
		ft_e_putstr("\n");
		exit(1);
	}
	return (0);
}

int	replace_args(t_list *list, va_list args_list)
{
	int		r;
	int		size;
	t_item *e;

	while (list != NULL)
	{
		e = (t_item *)list->content;
		if (is_format(e))
		{
			r = fill_arg(e->fmt, args_list);
			if (r < 0)
			{
				return (r);
			}
			e->str_len = e->fmt->size;
			e->str = (e->fmt->type == 'c' && *e->fmt->value == 0) ?
				ft_strjoin2(3, e->fmt->pad_left, e->fmt->prefix, e->fmt->value)
				: ft_strjoin2(4, e->fmt->pad_left, e->fmt->prefix, e->fmt->value, e->fmt->pad_right);
			free_format(e->fmt);
			e->fmt = NULL;
			//if (e->str_len < 0)
			//{
			//	return;
			//}
		}
		list = list->next;
	}
	return (0);
}