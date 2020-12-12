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

BOOL return_minus_one(t_fmt *fmt, const char *str)
{
	if (str == NULL || fmt->type != 's')
	{
		return FALSE;
	}
	//if ((fmt->length[0] == 'l' && fmt->length[1] == 'l'))
	//{
	//	return TRUE;
	//} 
	//if ( fmt->flags.is_alt_form == FALSE )
	//{
	//	return FALSE;
	//}
	if ( fmt->precision_set == TRUE && fmt->precision == 0)
	{
		return FALSE;
	}
	if (ft_contains("lLjzt", *fmt->length))
	{
		return TRUE;
	} 
	return FALSE;

}


t_fmt *pchar_to_string(t_fmt *fmt, const char *str)
{
	if (return_minus_one(fmt, str))
	{
		fmt->size = -1;
		return;
	}
	fmt->value = ft_strdup(str == NULL ? "(null)" : str);
	if (fmt->precision_set && fmt->precision == 0)
	{
		fmt->length[0] = 0;
	}
	return (fmt);
}