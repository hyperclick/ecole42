/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 12:30:12 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 12:30:15 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char *colorize_extensions(const char *cell, char *str)
{
	if (ft_starts_with(cell, '.'))
	{
		ft_strcpy(str, COLOR_GRAY);
		str += ft_strlen(COLOR_GRAY);
	}
	if (ft_str_ends_with(cell, ".c"))
	{
		ft_strcpy(str, COLOR_GREEN);
		str += ft_strlen(COLOR_GREEN);
	}
	if (ft_str_ends_with(cell, ".o"))
	{
		ft_strcpy(str, COLOR_RED);
		str += ft_strlen(COLOR_RED);
	}
	if (ft_str_ends_with(cell, ".a"))
	{
		ft_strcpy(str, COLOR_YELLOW);
		str += ft_strlen(COLOR_YELLOW);
	}
	return (str);
}

char *colorize(const char *cell, BOOL is_active, BOOL is_selected, char *str)
{
	if (is_active)
	{
		ft_strcpy(str, UNDERLINED);
		str += ft_strlen(UNDERLINED);
	}
	if (is_selected)
	{
		ft_strcpy(str, REVERSE_VIDEO_COLOR);
		str += ft_strlen(REVERSE_VIDEO_COLOR);
	}
	return (colorize_extensions(cell, str));
}