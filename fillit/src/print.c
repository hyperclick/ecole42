/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:44:21 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 11:44:22 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"

void	print_figure(t_t f)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putchar(f.a[i][j]);
		}
		ft_putchar('\n');
	}
}

void	print_figures(void)
{
	char	c;

	ft_putstr("figures:\n");
	c = 'A' - 1;
	while (++c < 'A' + get_figures_count())
	{
		print_figure(get_figure(c));
		ft_putchar('\n');
	}
	ft_putstr("-------------------------\n");
}

void	print_r(t_r r)
{
	int	i;
	int	j;

	i = 0;
	while (i < r.height)
	{
		j = 0;
		while (j < r.width)
		{
			ft_putchar(r.a[i][j]);
			++j;
		}
		if (i != r.height - 1)
		{
			ft_putchar('\n');
		}
		++i;
	}
}
