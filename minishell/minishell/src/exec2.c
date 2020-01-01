/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 12:26:24 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 12:26:25 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static pid_t	built_in_or_external(char **replaced_args, int c)
{
	pid_t	pid;

	pid = 0;
	if (!built_in_processed(replaced_args, c))
	{
		pid = exec2((const char**)replaced_args);
	}
	ft_free_array((void**)replaced_args, c);
	return (pid);
}

static pid_t	exec3(int c, char **args)
{
	char *replaced_args[c + 1];

	replaced_args[c] = NULL;
	env_replace_vars(replaced_args, (const char**)args);
	ft_free_null_term_array((void**)args);
	replace_back(replaced_args);
	debug_printf("after replace\n");
	debug_print_zt_array((const char**)replaced_args);
	return (built_in_or_external(replaced_args, c));
}

pid_t			exec(char *str)
{
	char	**args;
	int		c;

	args = ft_split3(str, " \t");
	free(str);
	c = ft_count_null_term_array((void*)args);
	return (exec3(c, args));
}
