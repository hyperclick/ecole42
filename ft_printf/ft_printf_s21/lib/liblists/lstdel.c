/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:20:34 by darugula          #+#    #+#             */
/*   Updated: 2019/09/16 21:20:36 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	lstdel(t_list **alst, void (*del)(void *))
{
	t_list *node;
	t_list *next;

	node = *alst;
	while (node)
	{
		next = node->next;
		del(node->content);
		free(node);
		node = next;
	}
	*alst = NULL;
}
