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
