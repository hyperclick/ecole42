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

void	process_blank(t_fmt *fmt)
{
	if (ft_contains("idaAeEfFgG", fmt->type)
		&& fmt->flags.blank_before_positive
		&& !fmt->flags.plus_before_positive)
	{
		if (fmt->prefix[0] != '-')
		{
			fmt->prefix = ft_str_prepend_and_free(" ", fmt->prefix);
		}
	}
}
