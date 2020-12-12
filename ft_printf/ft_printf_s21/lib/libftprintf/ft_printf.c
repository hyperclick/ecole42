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

char *ft_vstprintf(int *r, const char *format, va_list args_list)
{
	int		r2;
	char	*dst;

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
	r2 = replace_args(list, args_list);
	if (r2 < 0)
	{
		free_list(&list);
		return (ft_strdup(""));
	}
	dst = list_to_string(list, &r2);
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
