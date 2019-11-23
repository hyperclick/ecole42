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

#include "libft.h"

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

void		ft_env(int argc, char* const argv[], char* const env[])
{
	if (argc != 0)
	{
		ft_e_putstr("-minishell: env: too many arguments");
		return;
	}
	(void)argv;
	while (*env != NULL)
	{
		ft_putstr(*env++);
		ft_putchar('\n');
	}
}