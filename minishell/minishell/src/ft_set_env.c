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
















static void	replace_tilde(const char **a, char **r)
{
	char	*tmp;
	
	tmp = ft_strdup(*r == NULL ? *a : *r);
	if (ft_contains(tmp, '~'))
	{
		*r = ft_str_replace(tmp, "~", env_get_value("HOME"));
	}
	free(tmp);
}

static BOOL	replaced(char **r, const char **a)
{
	char	*value;
	
	value = env_get_value((*a + 1));
	if (value != NULL)
	{
		*r = ft_strdup(value);
		return (TRUE);
	}
	return (FALSE);
}

char		**env_replace_vars(char **r, const char **a)
{
	while (*a != NULL)
	{
		*r = NULL;
		if (ft_starts_with(*a, '$'))
		{
			if (!replaced(r, a))
			{
				a++;
				continue;
			}
		}
		replace_tilde(a, r);
		if (*r == NULL)
		{
			*r = ft_strdup(*a);
		}
		r++;
		a++;
	}
	*r = NULL;
	return (r);
}
