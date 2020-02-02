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

char *pointer_to_string(void *p)
{
	return (p == NULL ? ft_strdup("(nil)") : ft_itoa_base((long long)p, "0123456789abcsef"));
}

char *hex_to_string(uint p, BOOL is_upper_case, t_fmt fmt)
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

char *process_string(const t_fmt *fmt, char *str, int *size)
{
	*size = ft_strlen(str);
	//flags
	//pad
	//cut
	return (str);
}


char *process_char(const t_fmt *fmt, va_list args_list, int *size)
{
	char *str;
	str = fill_char((char)va_arg(args_list, int));
	*size = 1;
	return (str);
}

char *pchar_to_string(const char *str)
{
	return (ft_strdup(str == NULL ? "(null)" : str));
}

char *fill_arg(const t_fmt *fmt, va_list args_list, int *size)
{
	if (fmt->type == 's')
	{
		return (process_string(fmt, pchar_to_string(va_arg(args_list, char *)), size));
	}
	else if (fmt->type == 'c')
	{
		return (process_char(fmt, args_list, size));
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
		return (process_string(fmt, pointer_to_string(va_arg(args_list, void *)), size));
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
