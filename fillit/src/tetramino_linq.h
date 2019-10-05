/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino_linq.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:57:57 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 17:57:59 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAMINO_LINQ_H
# define TETRAMINO_LINQ_H

# include "tetramino.h"

t_elem	repeat(t_elem e, void *param);
t_r		r_map(t_r r, void *param, t_elem (*f)(t_elem, void*));
BOOL	all_empty(t_t t);
BOOL	t_any(t_t	t, int (*f)(char e));
#endif
