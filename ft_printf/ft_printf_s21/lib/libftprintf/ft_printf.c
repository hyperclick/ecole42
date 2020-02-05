/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
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
		//if (is_negative)
		//{
		//	fmt->width = -fmt->width;
		//}
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

char *format_to_string(t_fmt fmt)
{
	char	*flags;
	char	*width;
	char	*r;

	flags = flags_to_string(fmt.flags);
	width = fmt.width == DEFAULT_WIDTH ? ft_strdup("") : ft_itoa(fmt.width);
	r = ft_strjoin2(2, flags, width);
	free(flags);
	free(width);
	return (r);
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

char *try_parse_settings(char *format, t_fmt *fmt, t_list *list)
{
	format = try_parse_flags(format, fmt);
	//if (*format == 0)
	//{
	//	add_string(list, flags_to_string(fmt->flags));
	//}
	normalize_flags(fmt);
	format = try_parse_width(format, fmt);

	format = try_parse_type(format, fmt);
	if (fmt->type == 0)
	{
		add_string(list, format_to_string(*fmt));
	}
	else
	{
		add_format(list, fmt);
	}
	return (format);
}


char *try_extract_id(t_list *list, char *format)
{
	char *r;

	if (*format == '%')
	{
		add_string(list, "%");
		return (format + 1);
	}
	if (*format == 0)
	{
		return (format);
	}
	format = try_parse_settings(format, get_default_format(), list);
	return (format);
}

t_list *to_list(char *format, int *r)
{
	t_list *list;
	list = NULL;

	if (format == NULL)
	{
		*r = -1;
		return (list);
	}
	list = lst_new(create_string(""), -1);
	if (*format == 0)
	{
		*r = 0;
		return (list);
	}
	char *str;
	char *start;
	str = (char *)malloc(sizeof(format) + 1);
	start = str;
	while (*format != 0)
	{
		if (*format == '%')
		{
			*str = 0;
			str = start;
			add_string(list, str);
			if (*(format + 1) == 0)
			{
				*r = -1;
				return (list);
			}
			format = try_extract_id(list, format + 1);
			continue;
		}
		*str++ = *format++;
	}
	*str = 0;
	str = start;
	add_string(list, str);
	*r = 0;
	return (list);
}

int	to_string_get_size(t_list *list)
{
	int size;

	size = 0;
	while (list != NULL)
	{
		size += ((t_item *)list->content)->str_len;
		list = list->next;
	}
	return (size);
}

char *to_string(t_list *list, int *size)
{
	char *r;
	char *start;
	t_item *e;

	*size = to_string_get_size(list);
	r = (char *)malloc(sizeof(char) * (*size + 1));
	start = r;
	r[*size] = 0;
	while (list != NULL)
	{
		e = (t_item *)list->content;
		ft_strncpy(r, e->str, e->str_len);
		r += e->str_len;
		list = list->next;
	}
	*r = 0;
	return (start);
}

char *ft_vstprintf(int *r, const char *format, va_list args_list)
{
	int		r2;
	char *dst;

	if (format == NULL)
	{
		*r = -1;
		return (ft_strdup(""));
	}

	t_list *list;
	list = to_list((char *)format, r);
	if (list == NULL)
	{
		return (ft_strdup(""));
	}
	replace_args(list, args_list);
	dst = to_string(list, &r2);
	free_list(&list);
	if (*r == 0)
	{
		*r = r2;
	}
	return (dst);
}


int		ft_vsprintf(char *dst, const char *format, va_list args_list)
{
	int	r;
	char *str;

	str = ft_vstprintf(&r, format, args_list);
	ft_strcpy(dst, str);
	free(str);
	return (r);
}

int	ft_stprintf(char *dst, const char *format, ...)
{
	int		r;
	va_list	args_list;

	va_start(args_list, format);
	r = (ft_vsprintf(dst, format, args_list));
	va_end(args_list);
	return (r);
}

int	ft_vprintf_fd(int fd, const char *format, va_list args_list)
{
	char *dst;
	int r;

	dst = ft_vstprintf(&r, format, args_list);
	ft_putstr_fd(dst, fd);
	free(dst);
	return (r);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	int		r;
	va_list	args_list;

	va_start(args_list, format);
	r = ft_vprintf_fd(fd, format, args_list);
	va_end(args_list);
	return (r);
}

int	ft_printf(const char *format, ...)
{
	int		r;
	va_list	argptr;

	va_start(argptr, format);
	r = ft_vprintf_fd(STDOUT_FILENO, format, argptr);
	va_end(argptr);
	return (r);
}
