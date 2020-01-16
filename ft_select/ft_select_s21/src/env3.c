/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:36:09 by darugula          #+#    #+#             */
/*   Updated: 2019/09/10 10:36:23 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

BOOL	env_greater_than(t_list *a, t_list *b)
{
	const char	*key_a = env_extract_key(a->content);
	const char	*key_b = env_extract_key(b->content);
	int			r;

	r = ft_strcmp(key_a, key_b);
	free((char*)key_a);
	free((char*)key_b);
	return (r > 0);
}

void	env_free_one(void *item, size_t size)
{
	(void)size;
	free(item);
}

BOOL	key_equal(char *const key, t_list *n)
{
	const char	*current_key;
	BOOL		b;

	current_key = env_extract_key((const char*)n->content);
	b = ft_str_equals(key, current_key);
	free((char*)current_key);
	return (b);
}
