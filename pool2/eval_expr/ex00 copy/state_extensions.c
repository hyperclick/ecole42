/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_extensions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:36:17 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 21:36:21 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"
#include "includes/state.h"

char			*get_str(struct s_state *state)
{
	return (state->input.str[state->input.i]);
}

struct s_state	*set_position(struct s_state *dst, int i)
{
	dst->input.i = i;
	return (dst);
}

struct s_state	get_new_state(struct s_input input)
{
	struct s_state	state;

	state.operators[0] = '?';
	state.operators[1] = '?';
	state.operands[0] = INT_MIN;
	state.operands[1] = INT_MIN;
	state.operands[2] = INT_MIN;
	state.result = INT_MIN;
	state.input.str = input.str;
	set_position(&state, input.i);
	return (state);
}

void			add_operand(int operand, struct s_state *state)
{
	if (!is_operand_set(state->operands[0]))
	{
		state->operands[0] = operand;
		return ;
	}
	if (!is_operand_set(state->operands[1]))
	{
		state->operands[1] = operand;
		return ;
	}
	if (!is_operand_set(state->operands[2]))
	{
		state->operands[2] = operand;
		return ;
	}
	ft_putstr("!!! operands stack overflow");
	exit(1);
}

void			add_operator(char op, struct s_state *state)
{
	if (!is_operator_set(state->operators[0]))
	{
		state->operators[0] = op;
		return ;
	}
	if (!is_operator_set(state->operators[1]))
	{
		state->operators[1] = op;
		return ;
	}
	ft_putstr("!!! operators stack overflow");
	exit(1);
}
