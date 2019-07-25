/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:55:10 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 21:55:12 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H
# include "bool.h"

struct				s_input
{
	char			**str;
	int				i;
};

struct				s_state
{
	int				operands[3];
	char			operators[2];
	int				result;
	struct s_input	input;
};

char				*get_str(struct s_state *state);
struct s_state		get_new_state(struct s_input input);
struct s_state		*set_position(struct s_state *dst, int i);
BOOL				is_operand_set(int op);
BOOL				is_operator_set(char op);
BOOL				is_everything_set(struct s_state state);
BOOL				ready_to_calc(struct s_state state);
BOOL				is_anything_set(struct s_state state);
void				add_operand(int operand, struct s_state *state);
void				add_operator(char op, struct s_state *state);
BOOL				is_operand_0_set(struct s_state state);
BOOL				is_operand_1_set(struct s_state state);
BOOL				is_operand_2_set(struct s_state state);
BOOL				is_operator_0_set(struct s_state state);
BOOL				is_operator_1_set(struct s_state state);
void				print_state(struct s_state s);
#endif
