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

#include "minishell.h"

void		env_from_array(char *env[])
{
	if (env_get_g_env() != NULL)
	{
		ft_e_putstr("g_env != NULL\n");
		exit(1);
	}
	while (*env != NULL)
	{
		env_add_new(ft_lst_new(ft_strdup(*env), -1));
		env++;
	}
}

char		*env_get_value(const char *key)
{
	t_list	*n;
	char	*str;
	char	find[1000];

	find[0] = 0;
	ft_strcat(ft_strcat(find, key), "=");
	n = env_get_g_env();
	while (n != NULL)
	{
		if (ft_str_starts_with((const char*)n->content, find))
		{
			str = (char*)n->content;
			return (str + ft_strlen(find));
		}
		n = n->next;
	}
	return (NULL);
}

static char	*extract_kvp(t_list *n)
{
	return ((char*)n->content);
}

void		ft_env(int argc, char *const argv[])
{
	t_list	*env;

	if (argc != 0)
	{
		ft_e_putstr("-minishell: env: too many arguments");
		return ;
	}
	(void)argv;
	env = env_get_g_env();
	while (env != NULL)
	{
		ft_putstr(extract_kvp(env));
		ft_putchar('\n');
		env = env->next;
	}
}

char		**env_to_array(void)
{
	int		i;
	t_list	*env;
	int		count;
	char	**a;

	count = ft_lst_count(env_get_g_env()) + 1;
	a = (char**)malloc(sizeof(char*) * count);
	if (a == NULL)
	{
		ft_e_putstr("env_to_array failed");
		exit(1);
	}
	a[count - 1] = NULL;
	env = env_get_g_env();
	i = -1;
	while (++i < count - 1)
	{
		a[i] = extract_kvp(env);
		env = env->next;
	}
	return (a);
}
