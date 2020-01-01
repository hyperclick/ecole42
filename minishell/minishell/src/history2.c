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

#include "../libft/libft.h"
#include "history.h"

BOOL		h_has_previous(void)
{
	return (g_current == NULL ? g_last != NULL : g_current->prev != NULL);
}

BOOL		h_has_next(void)
{
	return ((g_current != NULL && g_current->list.next != NULL));
}

const char	*h_get_current(void)
{
	return ((const char*)g_current->list.content);
}

const char	*h_get_previous(void)
{
	g_current = g_current == NULL ? g_last : g_current->prev;
	return (h_get_current());
}

const char	*h_get_next(void)
{
	g_current = (t_d_list*)g_current->list.next;
	return (h_get_current());
}
