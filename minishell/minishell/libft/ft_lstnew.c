/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:21:04 by darugula          #+#    #+#             */
/*   Updated: 2019/09/16 21:21:07 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_init_new(t_list *node, void const *content
							, size_t content_size)
{
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	if (content == NULL)
	{
		node->content = NULL;
		node->content_size = 0;
		return (node);
	}
	node->content_size = content_size;
	node->content = (void*)content;
	return (node);
}

t_list		*ft_lst_new(void const *content, size_t content_size)
{
	return (ft_lst_init_new((t_list*)malloc(sizeof(t_list)), content
						, content_size));
}

t_d_list	*ft_dlst_new(void const *content, size_t content_size)
{
	t_d_list	*n;

	n = (t_d_list*)malloc(sizeof(t_d_list));
	n->prev = NULL;
	return ((t_d_list*)ft_lst_init_new((t_list*)n, content, content_size));
}
