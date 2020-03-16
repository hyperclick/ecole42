/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf_internal.h"

void	free_format(t_fmt* fmt)
{
	ft_free_not_null((void**)&fmt->prefix);
	ft_free_not_null((void**)&fmt->value);
	ft_free_not_null((void**)&fmt->pad_left);
	ft_free_not_null((void**)&fmt->pad_right);

	free(fmt);
	fmt = NULL;
}


t_item	*create_string(char* str)
{
	t_item* e;

	e = (t_item*)malloc(sizeof(t_item));
	e->str = str;// ft_strdup(str);
	e->str_len = ft_strlen(str);
	e->fmt = NULL;
	e->was_format = FALSE;
	return (e);
}

t_item	*create_format(const t_fmt* fmt)
{
	t_item* e;

	e = (t_item*)malloc(sizeof(t_item));
	e->fmt = (t_fmt*)fmt;
	e->str = NULL;
	e->str_len = 0;
	e->was_format = TRUE;
	return (e);
}

t_fmt	*get_default_format()
{
	t_fmt* f;

	f = (t_fmt*)malloc(sizeof(t_fmt));
	f->flags.adjust_left = FALSE;
	f->flags.blank_before_positive = FALSE;
	f->flags.is_alt_form = FALSE;
	f->flags.plus_before_positive = FALSE;
	f->flags.zero_pad = FALSE;
	f->width = DEFAULT_WIDTH;
	f->precision_set = FALSE;
	f->precision = DEFAULT_PRECISION;
	//ft_strcpy(f->length, "\0\0\0");
	f->length[0] = f->length[1] = f->length[2] = 0;
	f->type = 0;
	f->pad_left = NULL;
	f->pad_right = NULL;
	f->prefix = NULL;
	f->value = NULL;
	//f->value_is_negative = FALSE;
	return (f);
}
