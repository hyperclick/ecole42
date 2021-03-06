/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:37:59 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 11:38:00 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"

static t_t		g_figures[26];
static int		g_figures_count;

int		get_figures_count(void)
{
	return (g_figures_count);
}

void	set_figures_count(int count)
{
	g_figures_count = count;
}

void	add_figure(t_t t)
{
	g_figures[g_figures_count++] = t;
}

t_t		get_figure(char letter)
{
	return (g_figures[letter - 'A']);
}

char	*make_rest(char *rest)
{
	int		i;
	char	*start;

	start = rest;
	i = -1;
	while (++i < g_figures_count)
	{
		*rest = g_figures[i].letter;
		rest++;
	}
	*rest = 0;
	return (start);
}
