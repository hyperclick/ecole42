/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:56:24 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 21:56:26 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H

int		eval_expr(char *str);
int		calc_3(int a, char operator, int b);
void	calc_5(struct s_state *state);
int		get_precedence(char operator);
int		cmp_operators(char a, char b);

#endif
