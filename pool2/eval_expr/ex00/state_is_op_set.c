/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_is_op_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:42:39 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 21:42:41 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/state.h"

BOOL	is_operand_0_set(struct s_state state)
{
	return (is_operand_set(state.operands[0]));
}

BOOL	is_operand_1_set(struct s_state state)
{
	return (is_operand_set(state.operands[1]));
}

BOOL	is_operand_2_set(struct s_state state)
{
	return (is_operand_set(state.operands[0]));
}

BOOL	is_operator_0_set(struct s_state state)
{
	return (is_operator_set(state.operators[0]));
}

BOOL	is_operator_1_set(struct s_state state)
{
	return (is_operator_set(state.operators[1]));
}
