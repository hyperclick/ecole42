/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 08:21:14 by darugula          #+#    #+#             */
/*   Updated: 2019/07/17 08:21:16 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


#include <stdlib.h>
#include "../includes/ft_list.h"

t_list	*ft_create_elem(void *data)
{
	char	*str = (char*)data;
	//int q = *((int*)data);
	printf("%s start: ", __func__);
	//printf("%d\n", q);
	printf("*data = '%s', data = %p\n", str, data);
	t_list	*e;

	e = malloc(sizeof(*e));
	if (e)
	{
		e->data = data;
		e->next = NULL;
	}
	return (e);
}
