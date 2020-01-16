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

#define KEY_VALUE_SEPARATOR '='

const char	*env_extract_key(const char *kvp)
{
	return (ft_str_left_from(kvp, KEY_VALUE_SEPARATOR));
}

static void	env_replace(t_list *current, const char *kvp)
{
	free(current->content);
	current->content = (void*)kvp;
}

static BOOL	find(t_list *n, void *key)
{
	const char	*key_a;
	BOOL		r;

	key_a = env_extract_key((const char*)n->content);
	r = ft_strequ(key_a, key);
	free((char*)key_a);
	return (r);
}

static void	ft_set_env_impl(const char *key, const char *value)
{
	char	*new_env;
	t_list	*current;

	new_env = ft_strjoin2(3, key, "=", value);
	current = ft_lst_find(env_get_g_env(), (void*)key, find);
	if (current == NULL)
	{
		env_add_new(ft_lst_new(new_env, -1));
	}
	else
	{
		env_replace(current, new_env);
	}
}

void		ft_set_env(int argc, char *const argv[])
{
	if (argc > 2)
	{
		ft_e_putstr("-minishell: setenv: too many arguments");
		return ;
	}
	if (argc == 0)
	{
		ft_env(0, NULL);
		return ;
	}
	if (argc == 1)
	{
		ft_unset_env(argc, argv);
		return ;
	}
	ft_set_env_impl(argv[0], argv[1]);
}
