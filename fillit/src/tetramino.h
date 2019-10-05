/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:50:38 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 17:50:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAMINO_H
# define TETRAMINO_H

# include "../libft/libft.h"

typedef char	t_elem;
static const	t_elem	g_empty_elem = '.';
static const	t_elem	g_filled_elem = '#';

typedef struct	s_tetramino
{
	t_elem		a[4][4];
	char		letter;
}				t_t;

typedef struct	s_result
{
	int			height;
	int			width;
	t_elem		a[11][11];
	char		path[255];
	BOOL		found;
	int			deep;
}				t_r;

BOOL			is_empty(t_elem e);
BOOL			is_not_empty(t_elem e);

BOOL			is_neighbour_empty(t_t t, int row, int col);
BOOL			is_input_filled(t_elem e);
BOOL			validate_figure(t_t t);
t_t				normalize(t_t f);
BOOL			read_file(const char	*filename);

t_t				get_figure(char letter);
int				get_figures_count(void);
void			set_figures_count(int count);
void			add_figure(t_t t);
char			*make_rest(char *rest);

void			print_figure(t_t f);
void			print_figures(void);
void			print_r(t_r r);

t_r				append_path(t_r r, t_elem letter);
t_r				append(t_r r, int row, int col, t_t	t);
t_r				create_r(int width);

void			solve(const char *file_name);
t_r				fill(t_r r, const char rest[]);

#endif
