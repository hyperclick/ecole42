/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_is_op_set2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:51:55 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 21:51:57 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/state.h"
#include <limits.h>

BOOL	is_operand_set(int op)
{
	return (op != INT_MIN);
}

BOOL	is_operator_set(char op)
{
	return (op != '?');
}

BOOL	is_everything_set(struct s_state state)
{
	return
	(is_operand_set(state.operands[0])
	&& is_operand_set(state.operands[1])
	&& is_operand_set(state.operands[2])
	&& is_operator_set(state.operators[0])
	&& is_operator_set(state.operators[1]));
}

BOOL	ready_to_calc(struct s_state state)
{
	return (is_everything_set(state));
}

BOOL	is_anything_set(struct s_state state)
{
	return
	(is_operand_set(state.operands[0])
	|| is_operand_set(state.operands[1])
	|| is_operand_set(state.operands[2])
	|| is_operator_set(state.operators[0])
	|| is_operator_set(state.operators[1]));
}
