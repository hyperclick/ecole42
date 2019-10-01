/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 23:20:35 by darugula          #+#    #+#             */
/*   Updated: 2019/07/19 23:20:37 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#define NULL 0

void	btree_insert_data(
						t_btree **root,
						void *item,
						int (*cmpf)(void *, void *))
{
	if (!root || !cmpf)
		return ;
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) >= 0)
	{
		if ((*root)->right == NULL)
		{
			(*root)->right = btree_create_node(item);
			return ;
		}
		btree_insert_data(&((*root)->right), item, cmpf);
	}
	if (cmpf(item, (*root)->item) < 0)
	{
		if ((*root)->left == NULL)
		{
			(*root)->left = btree_create_node(item);
			return ;
		}
		btree_insert_data(&(*root)->left, item, cmpf);
	}
}
