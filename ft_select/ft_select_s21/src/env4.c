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

void		exec_ve(const char *argv[])
{
	int	r;

	debug_printf("exec(%s)\n", argv[0]);
	r = execve(argv[0], (char**)argv, env_to_array());
	if (r == -1)
	{
		debug_printf("execve(%s) failed\n", argv[0]);
		ft_e_putstr("Could not execute: ");
		ft_e_putstr(argv[0]);
		ft_e_putstr("\n");
	}
	debug_printf("execve returned: %d\n", r);
	ft_exit(2);
}

void		exec_ve2(const char *str)
{
	char	**args;

	args = ft_split3(str, " \t");
	exec_ve((const char **)args);
	debug_printf("should not be here\n");
	ft_free_null_term_array((void**)args);
}
