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

#include "minishell.h"

#define KEY_VALUE_SEPARATOR '='

t_list	*g_env = NULL;

char		*env_extract_value(char *env[], char *key)
{
	int	i;
	char		*str;

	i = -1;
	while (env[++i] != NULL)
	{
		if (ft_str_starts_with(env[i], key))
		{
			str = env[i];
			return (str + ft_strlen(key));
		}
	}
	return (NULL);
}

char* extract_kvp(t_list *n)
{
	return ((char*)n->content);
}

const char* env_extract_key(const char* kvp)
{
	return (ft_str_left_from(kvp, KEY_VALUE_SEPARATOR));
}

BOOL		env_greater_than(t_list* a, t_list* b)
{
	const char* key_a = env_extract_key(a->content);
	const char* key_b = env_extract_key(b->content);
	int		r = ft_strcmp(key_a, key_b);
	free((char*)key_a);
	free((char*)key_b);
	return (r > 0);
}

void		env_add_new(t_list* new)
{
	if (g_env == NULL)
	{
		g_env = new;
		return;
	}
	ft_lst_insert_sorted(&g_env, new, env_greater_than);
}

void		ft_env(int argc, char* const argv[])
{
	if (argc != 0)
	{
		ft_e_putstr("-minishell: env: too many arguments");
		return;
	}
	(void)argv;
	t_list *env = g_env;

	while (env != NULL)
	{
		ft_putstr(extract_kvp(env));
		ft_putchar('\n');
		env = env->next;
	}
}

BOOL		find(t_list *n, void *key)
{
	const char* key_a = env_extract_key((const char*)n->content);
	//const char* key_b = env_extract_key((const char*)content);
	BOOL r = ft_strequ(key_a, key);
	printf("key = '%s' key a = '%s', r = %d\n", (char *)key, key_a, r);
	free((char*)key_a);
	//free(key_b);
	return (r);
}

void env_free_one(void* item, size_t size)
{
	(void)size;
	free(item);
}


void		env_remove(char* const key)
{
	t_list *prev;
	prev = NULL;
	t_list *n = g_env;
	while (n != NULL)
	{
		if (ft_str_equals(key, env_extract_key((const char *)n->content)))
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
			return;
		}
		prev = n;
		n = n->next;
	}
	
	ft_e_putstr("-minishell: unsetenv: var not found: ");
	ft_e_putstr(key);
}

void		ft_unset_env(int argc, char* const argv[])
{
	if (argc != 1)
	{
		ft_e_putstr("-minishell: unsetenv: expected one argument\n");
		return;
	}
	//t_list* current = ft_lst_find(g_env, argv[0], find);
	//if (current == NULL)
	//{
	//	ft_e_putstr("-minishell: unsetenv: var not found: ");
	//	ft_e_putstr(argv[0]);
	//	return;
	//}
	env_remove(argv[0]);
}


void env_replace(t_list *current, const char *kvp)
{
	free(current->content);
	current->content = (void*) kvp;
}

void		ft_set_env(int argc, char* const argv[])
{
	if (argc > 2)
	{
		ft_e_putstr("-minishell: setenv: too many arguments");
		return;
	}
	if (argc == 0)
	{
		ft_env(0, NULL);
		return;
	}
	if (argc == 1)
	{
		ft_unset_env(argc, argv);
		return;
	}
	int len = ft_strlen(argv[0]) + 1;
	char key[len];
	key[len - 1] = 0;
	ft_strcpy(key, argv[0]);
	char* new_env = ft_strjoin2(3, argv[0], "=", argv[1]);
	//printf("argv[0] = '%s', argv[1] = '%s', new_env = '%s'\n", argv[0], argv[1], new_env);
	t_list* current = ft_lst_find(g_env, key, find);
	if (current == NULL)
	{
		env_add_new(ft_lstnew(new_env, -1));
	}
	else
	{
		env_replace(current, new_env);
	}
}

void		env_add_all(char *env[])
{
	if (g_env != NULL)
	{
		ft_e_putstr("g_env != NULL\n");
		exit(1);
	}
	while (*env != NULL)
	{
		env_add_new(ft_lstnew(ft_strdup(*env), -1));
		env++;
	}

}

void		env_free()
{
	if (g_env == NULL)
	{
		return;
	}
	ft_lstdel(&g_env, env_free_one);
}

char** env_to_array()
{
	int i;
	t_list* env ;
	int count = ft_lst_count(g_env) + 1;
	char** a;
	a = (char**)malloc(sizeof(char*) * count);
	if (a == NULL)
	{
		ft_e_putstr("env_to_array failed");
		exit(1);
	}
	a[count - 1] = NULL;
	env = g_env;
	i = -1;
	while (++i < count - 1)
	{
		a[i] = extract_kvp(env);
		env = env->next;
	}
	return (a);
}