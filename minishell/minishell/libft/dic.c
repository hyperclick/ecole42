/*_**************************************************************************_*/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 01:51:27 by darugula          #+#    #+#             */
/*   Updated: 2019/07/09 01:51:31 by darugula         ###   ########.fr       */
/*                                                                            */
/*_**************************************************************************_*/

#include "libft.h"

BOOL dic_is_empty(t_list* dic)
{
	return (dic_get_count(dic) == 0);
}

int dic_get_count(t_list* dic)
{
	return (ft_lst_count(dic));
}

t_kvp* get_kvp(t_list* n)
{
	return ((t_kvp*)n->content);
}
char** dic_get_keys(t_list* dic)
{
	char **start;
	int count = dic_get_count(dic);
	char** a = (char**) malloc(sizeof(char**) * (count + 1));
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

t_kvp** dic_get_kvps(t_list* dic)
{
	t_kvp** a_start;
	t_kvp** a = (t_kvp**) malloc(sizeof(t_kvp**) * dic_get_count(dic) + 1);
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
t_list* dic_find(t_list* dic, const char* key)
{
	t_kvp* kvp;
	while (dic != NULL)
	{
		kvp = get_kvp(dic);
		//printf("check %s\n", kvp->key);
		if (ft_strequ(key, kvp->key))
		{
			return (dic);
		}
		dic = dic->next;
	}
	return (NULL);
}

BOOL dic_contains_key(t_list* dic, const char* key)
{
	return (dic_find(dic, key) != NULL);
}

BOOL t_kvp_greater_than(t_kvp* a, t_kvp* b)
{
	return (ft_str_greater_than(a->key, b->key));
}

BOOL t_list_greater_than(t_list* a, t_list* b)
{
	return (t_kvp_greater_than((t_kvp*)a->content, (t_kvp*)b->content));
}

t_list* dic_add(t_list* dic, const char* key, const char* value)
{
	if (dic_contains_key(dic, key))
	{
		ft_e_putstr("dic_add failed: key already exists: ");
		ft_e_putstr(key);
		exit(1);
	}
	t_kvp* kvp;
	kvp = (t_kvp*)malloc(sizeof(t_kvp));
	kvp->key = ft_strdup(key);
	kvp->value = ft_strdup(value);
	t_list* n = ft_lst_new(kvp, -1);
	if (dic == NULL)
	{
		return (n);
	}
	ft_lst_insert_sorted(&dic, n, t_list_greater_than);
	//debug_printf("dic_add:\tkvp->key = '%s', &kvp->key = %p, kvp = %p\n", kvp->key, kvp->key, kvp);
	return(dic);
}

void dic_free_one_item(void* content, size_t size)
{
	(void)size;
	t_kvp* kvp = (t_kvp*)content;
	free(kvp->key);
	free(kvp->value);
	free(kvp);
}

void dic_free(t_list** dic)
{
	//if (*dic == NULL)
	//{
	//	return;
	//}
	ft_lstdel(dic, dic_free_one_item);
}

t_list* dic_remove(t_list* dic, const char* key)
{
	t_list* start;
	start = dic;
	t_list* prev;
	prev = NULL;
	//t_list* n = dic_find(dic, key);


	t_kvp* kvp;
	while (dic != NULL)
	{
		kvp = get_kvp(dic);
		if (ft_strequ(key, kvp->key))
		{
			if (prev == NULL)
			{
				start = dic->next;
			}
			else
			{
				prev->next = dic->next;
			}
			ft_lstdelone(&dic, dic_free_one_item);
			return (start);
		}
		if (prev == NULL)
		{
			prev = dic;
		}
		dic = dic->next;
	}

	ft_e_putstr("dic_remove failed: missing key: ");
	ft_e_putstr(key);
	exit(1);
}

void dic_replace(t_list* dic, const char* key, const char* value)
{
	t_kvp* kvp;
	t_list* n = dic_find(dic, key);
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

const char* dic_get_value(t_list* dic, const char* key)
{
	t_list* n = dic_find(dic, key);
	if (n == NULL)
	{
		ft_e_putstr("dic_get_value failed: missing key: ");
		ft_e_putstr(key);
		exit(1);
	}
	return(get_kvp(n)->value);
}
