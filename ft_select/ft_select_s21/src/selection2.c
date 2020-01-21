/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:29:04 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:29:06 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern int *g_selected;
extern int g_selected_count;

void		print_selection(char **options)
{
	int	i;
	BOOL		first;

	first = TRUE;
	i = -1;
	while (*options != NULL)
	{
		if (is_selected2(++i))
		{
			if (!first)
			{
				ft_putchar(' ');
			}
			else
			{
				first = FALSE;
			}
			ft_printf("%s", *options);
		}
		options++;
	}
}

void		dump_selection()
{
	int i;
	char *str;
	char *tmp;
	char *tmp2;

	debug_printf("selection changed (%d):\n", g_selected_count);
	i = -1;
	str = ft_strdup("");
	while (++i < g_selected_count)
	{
		tmp = str;
		tmp2 = ft_stprintf("%d, ", g_selected[i]);
		str = ft_strjoin(str, tmp2);
		free(tmp);
		free(tmp2);
	}
	tmp = str;
	str = ft_strjoin(str, "\n");
	free(tmp);
	debug_printf(str);
	free(str);
}

void		select_add(int offset)
{
	g_selected[g_selected_count++] = offset;
	dump_selection();
}

void		remove_from_selected_at(int n)
{
	while (n < g_selected_count)
	{
		g_selected[n] = g_selected[n + 1];
		n++;
	}
	g_selected[--g_selected_count] = -1;
}

BOOL		remove_if_selected(int offset)
{
	int n;

	n = ft_int_index_of(g_selected, g_selected_count, offset);
	if (n >= 0)
	{
		remove_from_selected_at(n);
		return (TRUE);
	}
	return (FALSE);
}