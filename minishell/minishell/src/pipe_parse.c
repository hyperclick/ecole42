/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:37:10 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:37:12 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_free(t_list **pipe)
{
	ft_lst_free(pipe);
}

t_list	*pipe_parse2(const char **cmds)
{
	t_list	*head;
	t_list	*prev;
	t_list	*n;

	head = NULL;
	prev = NULL;
	while (*cmds != NULL)
	{
		n = ft_lst_new(ft_strtrim2(*cmds, " \t"), -1);
		if (head == NULL)
		{
			head = n;
		}
		if (prev != NULL)
		{
			prev->next = n;
		}
		prev = n;
		cmds++;
	}
	return (head);
}

t_list	*pipe_parse(const char *str)
{
	char	**cmds;
	t_list	*list;

	debug_printf("pipe_parse(%s)\n", str);
	cmds = ft_split3(str, "|");
	debug_printf("cmd[0] = '%s'\n", cmds[0]);
	list = pipe_parse2((const char**)cmds);
	ft_free_null_term_array((void**)cmds);
	return (list);
}
