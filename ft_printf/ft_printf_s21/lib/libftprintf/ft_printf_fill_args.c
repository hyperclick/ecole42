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

char	*fill_string(char *arg)
{
	return (ft_strdup(arg == NULL ? "(NULL)" : arg));
}

char	*fill_char(char c)
{
	char *arg;

	arg = ft_strnew(1);
	arg[0] = c;
	return (arg);
}

char	*fill_pointer(void *p)
{
	return (ft_itoa((long long)p));
}

char	*fill_arg(const char *token, va_list args_list)
{
	if (ft_str_equals(token, "%s"))
	{
		return (fill_string(va_arg(args_list, char*)));
	}
	else if (ft_str_equals(token, "%c"))
	{
		return (fill_char((char)va_arg(args_list, int)));
	}
	else if (ft_str_equals(token, "%d"))
	{
		return (ft_itoa(va_arg(args_list, int)));
	}
	else if (ft_str_equals(token, "%p"))
	{
		return (fill_pointer(va_arg(args_list, void*)));
	}
	else
	{
		ft_e_putstr("unexpected format: ");
		ft_e_putstr(token);
		ft_e_putstr("\n");
		exit(1);
	}
}

void	ft_printf_fill_args(va_list args_list, int count, char **args
						, char **tokens)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		args[i] = fill_arg(tokens[i], args_list);
	}
}
