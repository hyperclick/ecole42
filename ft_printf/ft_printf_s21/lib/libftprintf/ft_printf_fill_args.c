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

char *fill_string(char *arg)
{
	return (ft_strdup(arg == NULL ? "(null)" : arg));
}

char *fill_char(char c)
{
	char *arg;

	arg = ft_strnew(1);
	arg[0] = c;
	return (arg);
}

char *hex_to_string(long long p, BOOL is_upper_case, t_fmt fmt)
{
	char *str;
	char *tmp;

	str = ft_itoa_base(p, is_upper_case ? "0123456789ABCDEF" : "0123456789abcdef");
	if (fmt.flags.is_alt_form && p != 0)
	{
		tmp = ft_strjoin(is_upper_case ? "0X" : "0x", str);
		free(str);
		str = tmp;
	}
	return  (str);
}

char *pointer_to_string(void *p, t_fmt fmt)
{
	fmt.flags.is_alt_form = TRUE;
	return (p == NULL ? ft_strdup("(nil)") : hex_to_string((long long)p, FALSE, fmt));
}

char *oct_to_string(uint p, t_fmt fmt)
{
	char *str;
	char *tmp;
	str = ft_itoa_base(p, "01234567");
	if (fmt.flags.is_alt_form && p != 0)
	{
		tmp = ft_strjoin("0", str);
		free(str);
		str = tmp;
	}
	return  (str);
}



char *process_sign(t_fmt fmt, char *str)
{
	char *dst;
	if (is_signed_number(fmt.type) && fmt.flags.plus_before_positive)
	{
		if (*str != '-')
		{
			dst = ft_strjoin("+", str);
			free(str);
			str = dst;
		}
	}
	return (str);
}

char *process_blank(t_fmt fmt, char *str)
{
	char *dst;
	if (is_signed_number(fmt.type)
		&& fmt.flags.blank_before_positive
		&& !fmt.flags.plus_before_positive)
	{
		if (*str != '-')
		{
			dst = ft_strjoin(" ", str);
			free(str);
			str = dst;
		}
	}
	return (str);
}

char *get_prefix(t_fmt fmt, char *str, char prefix[3])
{
	char *value;

	value = str;
	if (fmt.flags.zero_pad && is_number(fmt.type) && ft_strlen(str) != 0)
	{
		if (*str == '-' || *str == '+' || *str == ' ')
		{
			prefix[0] = str[0];
			value = ft_strdup(str + 1);
			free(str);
		}
		else if (*str == '0' && (str[1] == 'x' || str[1] == 'X'))
		{
			prefix[0] = str[0];
			prefix[1] = str[1];
			value = ft_strdup(str + 2);
			free(str);
		}
	}
	return (value);
}


char *process_width(t_fmt fmt, char *str, int *len)
{
	int	str_len;
	char *tmp;
	int		dst_len;
	char	prefix[] = "\0\0";
	char *pads;

	str_len = len == NULL ? ft_strlen(str) : *len;
	if (fmt.width <= str_len)
	{
		return (str);
	}

	str = get_prefix(fmt, str, prefix);

	pads = ft_str_repeat(fmt.flags.zero_pad && fmt.type != 'c' ? "0" : " ", fmt.width - str_len);
	dst_len = ft_strlen(pads) + str_len;
	tmp = malloc(sizeof(char) * (dst_len + 1));
	tmp[dst_len] = 0;
	if (fmt.flags.adjust_left)
	{
		ft_strcpy(tmp, str);
		ft_strcpy(tmp + str_len, pads);
	}
	else
	{
		ft_strcpy(tmp, prefix);
		ft_strcpy(tmp + ft_strlen(prefix), pads);
		ft_strcpy(tmp + ft_strlen(prefix) + ft_strlen(pads), str);
	}
	free(str);
	free(pads);
	if (len != NULL)
	{
		*len = dst_len;
	}
	return (tmp);
}

char *process_string(const t_fmt *fmt, char *str, int *size)
{
	//flags
	//pad
	//cut
	str = process_sign(*fmt, str);
	str = process_blank(*fmt, str);
	str = process_width(*fmt, str, NULL);

	*size = ft_strlen(str);
	return (str);
}


char *process_char(const t_fmt *fmt, va_list args_list, int *size)
{
	char *str;
	char	c;

	str = fill_char(va_arg(args_list, int));
	c = *str;
	*size = 1;
	str = process_width(*fmt, str, size);
	//if (c == 0)
	//{
	//	*size = *size + 1;
	//}
	return (str);
}

char *pchar_to_string(const char *str)
{
	return (ft_strdup(str == NULL ? "(null)" : str));
}

char *fill_arg(const t_fmt *fmt, va_list args_list, int *size)
{
	if (fmt->type == 'c')
	{
		return (process_char(fmt, args_list, size));
	}
	else if (fmt->type == 's')
	{
		return (process_string(fmt, pchar_to_string(va_arg(args_list, char *)), size));
	}
	else if (fmt->type == 'd' || fmt->type == 'i')
	{
		return (process_string(fmt, ft_itoa(va_arg(args_list, int)), size));
	}
	else if (fmt->type == 'u')
	{
		return (process_string(fmt, ft_itoa(va_arg(args_list, uint)), size));
	}
	else if (fmt->type == 'p')
	{
		return (process_string(fmt, pointer_to_string(va_arg(args_list, void *), *fmt), size));
	}
	else if (fmt->type == 'x' || fmt->type == 'X')
	{
		return (process_string(fmt, hex_to_string(va_arg(args_list, uint), fmt->type == 'X', *fmt), size));
	}
	else if (fmt->type == 'o')
	{
		return (process_string(fmt, oct_to_string(va_arg(args_list, uint), *fmt), size));
	}
	else
	{
		ft_e_putstr("unexpected format: ");
		ft_putchar_fd(fmt->type, STDERR_FILENO);
		ft_e_putstr("\n");
		exit(1);
	}
}

void	replace_args(t_list *list, va_list args_list)
{
	int		size;
	t_item *e;

	while (list != NULL)
	{
		e = (t_item *)list->content;
		if (is_format(e))
		{
			e->str = fill_arg(e->fmt, args_list, &size);
			e->str_len = size;
			free(e->fmt);
			e->fmt = NULL;
		}
		list = list->next;
	}
}
