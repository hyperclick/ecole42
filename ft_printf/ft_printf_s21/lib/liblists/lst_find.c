/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:20:43 by darugula          #+#    #+#             */
/*   Updated: 2019/09/16 21:20:44 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

t_list		*lst_find(t_list *lst, void *param, BOOL (*f)(t_list *, void *))
{
	if (lst == NULL || f == NULL)
	{
		return (NULL);
	}
	if (f(lst, param))
	{
		return (lst);
	}
	return (lst_find(lst->next, param, f));
}
