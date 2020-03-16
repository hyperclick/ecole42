/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_internal.h"

BOOL	is_string(t_item *e)
{
	return (e->str != NULL);
}

BOOL	is_format(t_item *e)
{
	return (e->fmt != NULL);
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
	list = lst_new(create_string(ft_strdup("")), -1);
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
			add_string(list, ft_strdup(str));
			format = try_extract_id(list, format + 1, r);
			if (*r < 0)
			{
				return (list);
			}
			continue;
		}
		*str++ = *format++;
	}
	*str = 0;
	str = start;
	add_string(list, ft_strdup(str));
	free(start);
	*r = 0;
	return (list);
}
