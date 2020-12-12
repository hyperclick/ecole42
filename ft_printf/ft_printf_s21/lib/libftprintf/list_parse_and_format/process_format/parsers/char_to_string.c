/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_printf_internal.h"

t_fmt* char_to_string(t_fmt* fmt, long long int c)
{
	fmt->value = ft_strnew(1);
	fmt->value[0] = c;

	//if (!(fmt->length[0] == 'l' && fmt->length[1] == 'l') && ((c > 255 || c < 0) && ft_contains("l", *fmt->length)))//INT_MAX)
	//if ((c > 255 || c < 0) && (ft_contains("l", *fmt->length) || fmt->length[0] == 'L' || fmt->length[0] == 'j'))//ft_contains("hlLjzt", fmt->length[0] ))
	if ((c > 255 || c < 0) && (ft_contains("lLjzt", *fmt->length) ))//h
	{
		fmt->size = -1;
	}
	else if (fmt->value[0] == 0)
	{
		fmt->size = 1;
	}
	return (fmt);
}
