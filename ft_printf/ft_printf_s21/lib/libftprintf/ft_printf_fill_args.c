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

void	process_sign(t_fmt *fmt)
{
	if (is_signed_number(fmt->type) && fmt->flags.plus_before_positive)
	{
		if (fmt->prefix[0] != '-')
		{
			fmt->prefix = ft_str_prepend_and_free("+", fmt->prefix);
		}
	}
}

char* ft_str_prepend_and_free(const char *prefix, char *str)
{
	char* tmp;

	tmp = str;
	str = ft_strjoin(prefix, str);
	free(tmp);
	return (str);
}

void	process_blank(t_fmt *fmt)
{
	if (is_signed_number(fmt->type)
		&& fmt->flags.blank_before_positive
		&& !fmt->flags.plus_before_positive)
	{
		if (fmt->prefix[0] != '-')
		{
			fmt->prefix = ft_str_prepend_and_free(" ", fmt->prefix);
		}
	}
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
	pads = ft_str_repeat(fmt->flags.zero_pad && fmt->type != 'c' ? "0" : " ", fmt->width - fmt->size);
	//fmt->size = ft_strlen(pads) + fmt->size;

	if (fmt->flags.adjust_left)
	{
		fmt->pad_right = pads;
		//char* tmp = fmt->value;
		//fmt->value = malloc(sizeof(char) * (ft_strlen(pads) + fmt->size + 1));
		//ft_strcpy(fmt->value, );
	}
	else
	{
		if (pads[0] == '0')
		{
			fmt->value = ft_str_prepend_and_free(pads, fmt->value);
		}
		else
		{
			fmt->prefix = ft_str_prepend_and_free(pads, fmt->prefix);			
		}
		free(pads);
	}
}

void	process_precision(t_fmt *fmt)
{
	if (fmt->precision < 0 || !is_int_number(fmt->type))
	{
		return;
	}
	if (fmt->precision == 0 && ft_strequ(fmt->value, "0"))
	{
		fmt->value[0] = 0;
		return;
	}

	int	diff;
	char *prefix;

	diff = ft_strlen(fmt->value) - fmt->precision;
	if (diff > 0)
	{
	//tmp = fmt->value;
		//str = ft_strsub(str, 0, fmt.precision);
		//free(tmp);
	}
	else if (diff < 0)
	{
		prefix = ft_str_repeat("0", -diff);
		fmt->value = ft_str_prepend_and_free(prefix, fmt->value);
		free(prefix);
	}
}

char *process_string(t_fmt *fmt)
{
	if (fmt->prefix == NULL)
	{
		fmt->prefix = ft_strdup("");
	}
	recalc_size(fmt);
	process_precision(fmt);
	recalc_size(fmt);
	process_sign(fmt);
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

	return (NULL);
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

char *fill_arg(t_fmt *fmt, va_list args_list)
{
	if (fmt->type == 'c')
	{
		return (process_string(char_to_string(fmt, va_arg(args_list, int))));
	}
	else if (fmt->type == 's')
	{
		return (process_string(pchar_to_string(fmt, va_arg(args_list, char *))));
	}
	else if (fmt->type == 'd' || fmt->type == 'i')
	{
		return (process_string(int_to_string(fmt, va_arg(args_list, int))));
	}
	else if (fmt->type == 'u')
	{
		return (process_string(uint_to_string(fmt, va_arg(args_list, uint))));
	}
	else if (fmt->type == 'p')
	{
		return (process_string(pointer_to_string(va_arg(args_list, void *), fmt)));
	}
	else if (fmt->type == 'x' || fmt->type == 'X')
	{
		return (process_string(hex_to_string(va_arg(args_list, uint), fmt->type == 'X', fmt)));
	}
	else if (fmt->type == 'o')
	{
		return (process_string(oct_to_string(va_arg(args_list, uint), fmt)));
	}
	else
	{
		ft_e_putstr("unexpected format: ");
		ft_putchar_fd(fmt->type, STDERR_FILENO);
		ft_e_putstr("\n");
		exit(1);
	}
}

char* join_zero_char(t_fmt *fmt)
{
	char* r;

	r = ft_strjoin2(3, fmt->pad_left, fmt->prefix, fmt->value);
}

void	replace_args(t_list *list, va_list args_list)
{
	int		size;
	t_item	*e;

	while (list != NULL)
	{
		e = (t_item *)list->content;
		if (is_format(e))
		{
			fill_arg(e->fmt, args_list);
			e->str = (e->fmt->type == 'c' && *e->fmt->value == 0) ?
				ft_strjoin2(3, e->fmt->pad_left, e->fmt->prefix, e->fmt->value)
				: ft_strjoin2(4, e->fmt->pad_left, e->fmt->prefix, e->fmt->value, e->fmt->pad_right);
			e->str_len = e->fmt->size;
			free_format(e->fmt);
			e->fmt = NULL;
		}
		list = list->next;
	}
}