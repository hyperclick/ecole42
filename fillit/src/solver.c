/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:33:51 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 17:33:57 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"
#include "result_checks.h"

BOOL	is_empty(t_elem e)
{
	return (e == EMPTY_ELEM);
}

BOOL	is_not_empty(t_elem e)
{
	return (!is_empty(e));
}

t_r		try_append(t_r r, t_t f, const char rest[])
{
	t_r		new_r;
	char	next_rest[27];
	int		i;
	int		j;

	new_r.found = FALSE;
	i = -1;
	while (++i < r.height)
	{
		j = -1;
		while (++j < r.width)
		{
			if (can_append(r, i, j, f))
			{
				new_r = append(r, i, j, f);
				ft_strcpy(next_rest, rest);
				ft_str_remove_at(next_rest, 0);
				new_r = fill(new_r, next_rest);
				if (new_r.found)
					return (new_r);
			}
		}
	}
	return (new_r);
}

t_r		fill(t_r r, const char rest[])
{
	t_t		f;
	t_r		new_r;

	r.deep++;
	if (ft_strlen(rest) == 0)
	{
		r.found = TRUE;
		return (r);
	}
	f = get_figure(rest[0]);
	new_r = try_append(r, f, rest);
	if (new_r.found)
	{
		return (new_r);
	}
	return (r);
}

void	solve(const char *file_name)
{
	char	rest[27];
	int		width;
	int		max_width;
	t_r		r;

	if (read_file(file_name) == FALSE || get_figures_count() == 0)
	{
		ft_putstr("error\n");
		exit(5);
	}
	width = ft_sqrt_up(get_figures_count() * 4);
	max_width = width + 12;
	r.found = FALSE;
	while (width < max_width && r.found == FALSE)
	{
		r = fill(create_r(width), make_rest(rest));
		width++;
	}
	print_r(r);
}
