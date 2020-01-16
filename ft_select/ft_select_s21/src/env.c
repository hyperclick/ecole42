/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:36:09 by darugula          #+#    #+#             */
/*   Updated: 2019/09/10 10:36:23 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list *g_env = NULL;

t_list		*env_get_g_env(void)
{
	return (g_env);
}

void		env_add_new(t_list *new)
{
	if (g_env == NULL)
	{
		g_env = new;
		return ;
	}
	ft_lst_insert_sorted(&g_env, new, env_greater_than);
}

static void	env_remove(char *const key)
{
	t_list		*prev;
	t_list		*n;

	prev = NULL;
	n = env_get_g_env();
	while (n != NULL)
	{
		if (key_equal(key, n))
		{
			if (prev == NULL)
			{
				g_env = n->next;
			}
			else
			{
				prev->next = n->next;
			}
			ft_lstdelone(&n, env_free_one);
			return ;
		}
		prev = n;
		n = n->next;
	}
	ft_e_ft_putstr_and_free(
		ft_strjoin2(3, "-minishell: var not found: ", key, "\n"));
}

void		ft_unset_env(int argc, char *const argv[])
{
	if (argc != 1)
	{
		ft_e_putstr("-minishell: unsetenv: expected one argument\n");
		return ;
	}
	env_remove(argv[0]);
}

void		env_free(void)
{
	if (g_env == NULL)
	{
		return ;
	}
	ft_lstdel(&g_env, env_free_one);
}
