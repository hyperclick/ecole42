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
	debug_printf("free g_commands\n");
	ft_free_null_term_array((void**)g_commands);
	g_commands = NULL;
}

static char	*trim(char *str, int *r)
{
	char	*trimmed;

	trimmed = ft_strtrim2(str, "\t ");
	free(str);
	str = NULL;
	if (ft_str_is_empty(trimmed))
	{
		free(trimmed);
		trimmed = NULL;
		*r = 0;
	}
	return (trimmed);
}

static char	*remove_comment_checked(char *s, int *r)
{
	char	*no_comments;

	debug_printf("trimmed = %s\n", s);
	no_comments = ft_str_remove_comment(s, '#');
	debug_printf("no comments = %s\n", no_comments);
	free(s);
	s = NULL;
	if (ft_str_is_empty(no_comments))
	{
		free(no_comments);
		no_comments = NULL;
		*r = 0;
	}
	return (no_comments);
}

static BOOL	check_words_count(char *s, int *r)
{
	int count;

	count = ft_count_words(s, ";");
	if (count == 0)
	{
		ft_e_putstr("minishell: syntax error near unexpected token `;'\n");
		debug_printf("minishell: syntax error near unexpected token `;'\n");
		free(s);
		*r = 1;
		return (FALSE);
	}
	return (TRUE);
}

static int	process_commands(char *s)
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

int			process_command(const char *str)
{
	int		r;
	char	*s;

	r = -200;
	debug_printf("\n");
	debug_printf("-----------------------\n");
	debug_printf("process command: '%s'\n", str);
	s = replace_quoted(str);
	if ((s = trim(s, &r)) == NULL
		|| (s = remove_comment_checked(s, &r)) == NULL
		|| !check_words_count(s, &r))
	{
		return (r);
	}
	r = process_commands(s);
	debug_printf("command processed: '%s'\n", str);
	debug_printf("-------------------------\n");
	debug_printf("\n");
	return (r);
}
