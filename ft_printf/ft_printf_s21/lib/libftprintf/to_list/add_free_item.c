/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_internal.h"

void	free_item(void *content)
{
	t_item *e;

	e = (t_item *)content;
	if (is_format(e))
	{
		free_format(e->fmt);
	}
	else if (is_string(e))
	{
		free(e->str);
	}
	free((void *)e);
}

void	free_list(t_list** list)
{
	lstdel(list, free_item);
}

void	add_string(t_list* list, char* str)
{
	if (*str == 0)
	{
		free(str);
		str = NULL;
		return;
	}
	lst_append(list, lst_new(create_string(str), -1));
}

void	add_format(t_list* list, const t_fmt* fmt)
{
	lst_append(list, lst_new(create_format(fmt), -1));
}
