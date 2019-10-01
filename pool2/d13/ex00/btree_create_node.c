/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:42:57 by darugula          #+#    #+#             */
/*   Updated: 2019/07/18 19:42:59 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree		*node;

	node = malloc(sizeof(t_btree));
	if (node != NULL)
	{
		node->left = NULL;
		node->right = NULL;
		node->item = item;
	}
	return (node);
}
