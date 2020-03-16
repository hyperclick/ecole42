/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pchar_to_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_printf_internal.h"


t_fmt* pchar_to_string(t_fmt* fmt, const char* str)
{
	fmt->value = ft_strdup(str == NULL ? "(null)" : str);
	if (fmt->precision_set && fmt->precision == 0)
	{
		fmt->length[0] = 0;
	}
	return (fmt);
}