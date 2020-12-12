/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_internal.h"

int	replace_args(t_list *list, va_list args_list)
{
	int		r;
	int		size;
	t_item	*e;

	while (list != NULL)
	{
		e = (t_item *)list->content;
		if (is_format(e))
		{
			r = process_type(e->fmt, args_list);
			if (r < 0)
			{
				return (r);
			}
			e->str_len = e->fmt->size;
			if (e->str_len == -1)
			{
				e->str = ft_strdup("should not see this as well");
			}
			else
			{
				e->str = (e->fmt->type == 'c' && *e->fmt->value == 0) ?
				ft_strjoin2(3, e->fmt->pad_left, e->fmt->prefix, e->fmt->value)
				: ft_strjoin2(4, e->fmt->pad_left, e->fmt->prefix, e->fmt->value, e->fmt->pad_right);
			}
			free_format(e->fmt);
			e->fmt = NULL;
		}
		list = list->next;
	}
	return (0);
}