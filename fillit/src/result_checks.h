/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_checks.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:32:19 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 17:32:23 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESULT_CHECKS_H
# define RESULT_CHECKS_H

BOOL	is_out_of_square(t_r r, int row, int col);
BOOL	is_overlap(t_r r, int row, int col);
BOOL	has_a_neighbour(t_r r, int row, int col);
BOOL	can_append(t_r r, int row, int col, t_t t);

#endif
