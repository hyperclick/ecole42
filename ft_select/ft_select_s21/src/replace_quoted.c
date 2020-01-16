/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_quoted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:36:10 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:36:12 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_list	*g_quoted_params = NULL;

char		*add_quote(char *dst, const char *prefix, const char *value)
{
	char	*itoa;
	int		count;
	char	key[200];

	count = dic_get_count(g_quoted_params) + 1;
	ft_strcpy(key, prefix);
	itoa = ft_itoa(count);
	ft_strcpy(key + ft_strlen(prefix), itoa);
	free(itoa);
	g_quoted_params = dic_add(g_quoted_params, key, value);
	ft_strcpy(dst, key);
	debug_printf("quote replaced: '%s' -> '%s'\n"
				, dic_get_value(g_quoted_params, key), key);
	return (dst + ft_strlen(key));
}

void		replace_back(char *a[])
{
	char	**keys;
	char	**keys_start;
	char	*tmp;

	keys = dic_get_keys(g_quoted_params);
	keys_start = keys;
	while (*a != NULL)
	{
		debug_printf("processing %s\n", *a);
		while (*keys != NULL)
		{
			if (ft_str_contains(*a, *keys))
			{
				tmp = *a;
				*a = ft_str_replace(*a, *keys
					, dic_get_value(g_quoted_params, *keys));
				free((char*)tmp);
			}
			keys++;
		}
		keys = keys_start;
		a++;
	}
	ft_free_null_term_array((void**)keys_start);
}

void		free_quoted_params(void)
{
	dic_free(&g_quoted_params);
	if (g_quoted_params != NULL)
	{
		debug_printf("ERROR\n");
		exit(1);
	}
}
