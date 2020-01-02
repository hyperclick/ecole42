/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:50:14 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:50:16 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL		dic_is_empty(t_list *dic)
{
	return (dic_get_count(dic) == 0);
}

int			dic_get_count(t_list *dic)
{
	return (ft_lst_count(dic));
}

t_kvp		*get_kvp(t_list *n)
{
	return ((t_kvp*)n->content);
}

char		**dic_get_keys(t_list *dic)
{
	char	**start;
	int		count;
	char	**a;

	count = dic_get_count(dic);
	a = (char**)malloc(sizeof(char**) * (count + 1));
	start = a;
	while (dic != NULL)
	{
		*a = ft_strdup(get_kvp(dic)->key);
		dic = dic->next;
		a++;
	}
	*a = (char*)NULL;
	return (start);
}

t_kvp		**dic_get_kvps(t_list *dic)
{
	t_kvp **a_start;
	t_kvp **a;

	a = (t_kvp**)malloc(sizeof(t_kvp**) * (dic_get_count(dic) + 1));
	a_start = a;
	while (dic != NULL)
	{
		*a = get_kvp(dic);
		dic = dic->next;
		a++;
	}
	*a = NULL;
	return (a_start);
}
