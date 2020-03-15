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

#include "../../ft_printf_internal.h"

int	process_type(t_fmt *fmt, va_list args_list)
{
	if (fmt->type == 'c')
	{
		process_string(char_to_string(fmt, (int)va_arg(args_list, int)));
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