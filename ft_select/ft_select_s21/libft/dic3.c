/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:50:14 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:50:16 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		dic_free_one_item(void *content, size_t size)
{
	t_kvp *kvp;

	kvp = (t_kvp*)content;
	free(kvp->key);
	free(kvp->value);
	free(kvp);
	(void)size;
}

void		dic_free(t_list **dic)
{
	ft_lstdel(dic, dic_free_one_item);
}

static BOOL	removed(t_list *dic, const char *key, t_list **prev, t_list **start)
{
	if (ft_strequ(key, get_kvp(dic)->key))
	{
		if (*prev == NULL)
		{
			*start = (dic)->next;
		}
		else
		{
			(*prev)->next = (dic)->next;
		}
		return (TRUE);
	}
	if (*prev == NULL)
	{
		*prev = dic;
	}
	return (FALSE);
}

t_list		*dic_remove(t_list *dic, const char *key)
{
	t_list	*prev;
	t_list	*start;

	start = dic;
	prev = NULL;
	while (dic != NULL)
	{
		if (removed(dic, key, &prev, &start))
		{
			ft_lstdelone(&dic, dic_free_one_item);
			return (start);
		}
		dic = dic->next;
	}
	ft_e_ft_putstr_and_free(
		ft_strjoin2(3, "dic_remove failed: missing key: ", key, "\n"));
	exit(1);
}

void		dic_replace(t_list *dic, const char *key, const char *value)
{
	t_kvp	*kvp;
	t_list	*n;

	n = dic_find(dic, key);
	if (n == NULL)
	{
		ft_e_putstr("dic_replace failed: missing key: ");
		ft_e_putstr(key);
		exit(1);
	}
	kvp = get_kvp(n);
	free(kvp->value);
	kvp->value = ft_strdup(value);
}
