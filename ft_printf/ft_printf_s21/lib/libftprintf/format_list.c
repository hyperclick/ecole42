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

#include "ft_printf_internal.h"

void	free_if_not_null(void **p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

void	free_format(t_fmt* fmt)
{
	free_if_not_null((void**)&fmt->prefix);
	free_if_not_null((void**)&fmt->value);
	free_if_not_null((void**)&fmt->pad_left);
	free_if_not_null((void**)&fmt->pad_right);

	free(fmt);
	fmt = NULL;
}

void	free_item(void* content)
{
	t_item* e;

	e = (t_item*)content;
	if (is_format(e))
	{
		free(e->fmt);
	}
	else if (is_string(e))
	{
		free(e->str);
	}
	free((void*)e);
}

void	free_list(t_list** list)
{
	lstdel(list, free_item);
}

//void	remove_empty(t_list **list)
//{
//	t_list *head;
//
//	head = *list;
//
//
//}

void	add_string(t_list* list, const char* str)
{
	if (*str == 0)
	{
		return;
	}
	lst_append(list, lst_new(create_string(str), -1));
}

void	add_format(t_list* list, const t_fmt* fmt)
{
	lst_append(list, lst_new(create_format(fmt), -1));
}

t_item* create_string(const char* str)
{
	t_item* e;

	e = (t_item*)malloc(sizeof(t_item));
	e->str = ft_strdup(str);
	e->str_len = ft_strlen(str);
	e->fmt = NULL;
	return (e);
}

t_item* create_format(const t_fmt* fmt)
{
	t_item* e;

	e = (t_item*)malloc(sizeof(t_item));
	e->fmt = (t_fmt*)fmt;
	e->str = NULL;
	e->str_len = 0;
	return (e);
}

BOOL	is_string(t_item* e)
{
	return (e->str != NULL);
}

BOOL	is_format(t_item* e)
{
	return (e->fmt != NULL);
}

BOOL	is_format2(void* e)
{
	return (is_format((t_item*)e));
}

int		count_format(t_list* list)
{
	return (lst_count_if(list, is_format2));
}


t_fmt* get_default_format()
{
	t_fmt* f;

	f = (t_fmt*)malloc(sizeof(t_fmt));
	f->flags.adjust_left = FALSE;
	f->flags.blank_before_positive = FALSE;
	f->flags.is_alt_form = FALSE;
	f->flags.plus_before_positive = FALSE;
	f->flags.zero_pad = FALSE;
	f->width = DEFAULT_WIDTH;
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

int		recalc_size(t_fmt* fmt)
{
	fmt->size = ft_strlen(fmt->value);
	if (fmt->type == 'c' && fmt->size == 0)
	{
		fmt->size = 1;
	}
	if (fmt->pad_right != NULL)
	{
		fmt->size += ft_strlen(fmt->pad_right);
	}
	fmt->size += ft_strlen(fmt->prefix);
	if (fmt->pad_left != NULL)
	{
		fmt->size += ft_strlen(fmt->pad_left);
	}
	return (fmt->size);
}