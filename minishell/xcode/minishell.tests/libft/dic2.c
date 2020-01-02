/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:50:14 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:50:16 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*dic_find(t_list *dic, const char *key)
{
	t_kvp *kvp;

	while (dic != NULL)
	{
		kvp = get_kvp(dic);
		if (ft_strequ(key, kvp->key))
		{
			return (dic);
		}
		dic = dic->next;
	}
	return (NULL);
}

BOOL		dic_contains_key(t_list *dic, const char *key)
{
	return (dic_find(dic, key) != NULL);
}

BOOL		t_kvp_greater_than(t_kvp *a, t_kvp *b)
{
	return (ft_str_greater_than(a->key, b->key));
}

BOOL		t_list_greater_than(t_list *a, t_list *b)
{
	return (t_kvp_greater_than((t_kvp*)a->content, (t_kvp*)b->content));
}

t_list		*dic_add(t_list *dic, const char *key, const char *value)
{
	t_kvp	*kvp;
	t_list	*n;

	if (dic_contains_key(dic, key))
	{
		ft_e_putstr("dic_add failed: key already exists: ");
		ft_e_putstr(key);
		exit(1);
	}
	kvp = (t_kvp*)malloc(sizeof(t_kvp));
	kvp->key = ft_strdup(key);
	kvp->value = ft_strdup(value);
	n = ft_lst_new(kvp, -1);
	if (dic == NULL)
	{
		return (n);
	}
	ft_lst_insert_sorted(&dic, n, t_list_greater_than);
	return (dic);
}
