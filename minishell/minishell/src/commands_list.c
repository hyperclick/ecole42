/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 12:24:18 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 12:24:25 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_commands = NULL;

void	free_commands(void)
{
	if (g_commands != NULL)
	{
		debug_printf("free g_commands\n");
		ft_free_null_term_array((void**)g_commands);
		g_commands = NULL;
	}
}

int		process_commands(char *s)
{
	int		r;
	char	**commands;

	commands = ft_split3(s, ";");
	free(s);
	if (g_commands != NULL)
	{
		ft_e_putstr("g_commands != NULL\n");
		ft_exit(1);
	}
	g_commands = commands;
	while (*commands != NULL)
	{
		r = process_one_command(*commands);
		if (r != 0)
		{
			break ;
		}
		commands++;
	}
	free_quoted_params();
	free_commands();
	return (r);
}
