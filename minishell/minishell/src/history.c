/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:00:51 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:00:52 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

t_d_list	*g_head = NULL;
t_d_list	*g_current = NULL;
t_d_list	*g_last = NULL;

void		h_append(const char *content)
{
	t_d_list	*l;

	l = ft_dlst_new(content, -1);
	l->prev = g_last;
	if (g_last == NULL)
	{
		g_last = l;
		g_head = l;
		return ;
	}
	g_last->list.next = (t_list*)l;
	g_last = l;
	g_current = NULL;
}

void		h_free(void)
{
	if (g_head == NULL)
	{
		return ;
	}
	ft_lst_free((t_list**)&g_head);
	g_last = NULL;
	g_current = NULL;
	if (g_head != NULL)
	{
		debug_printf("g_head != NULL\n");
		exit(1);
	}
}
