/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:15:19 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 21:15:21 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"
#include <limits.h>
#include "includes/state.h"
#include "includes/calc.h"

BOOL	can_exit(struct s_state *s)
{
	if (is_operand_set(s->operands[2]))
	{
		ft_putstr("can_exit:\toperands[2] = ");
		ft_putchar(s->operands[2]);
		ft_putchar('\n');
		exit(1);
	}
	if (is_operator_set(s->operators[1]))
	{
		ft_putstr("can_exit:\toperators[1] = ");
		ft_putchar(s->operators[1]);
		ft_putchar('\n');
		s->result = INT_MIN;
		return (TRUE);
	}
	if (
		is_operator_set(s->operators[0])
		&& is_operand_set(s->operands[0])
		&& is_operand_set(s->operands[1]))
	{
		s->result = calc_3(s->operands[0], s->operators[0], s->operands[1]);
		s->operands[0] = INT_MIN;
		s->operators[0] = '?';
		s->operands[1] = INT_MIN;
		print_state(*s);
		return (can_exit(s));
	}
	if (is_operand_set(s->result))
	{
		if (is_anything_set(*s))
		{
			ft_putstr("ready to exit but stack is not empty\n");
			s->result = INT_MIN;
		}
		return (TRUE);
	}
	if (is_operand_set(s->operands[0]))
	{
		s->result = s->operands[0];
		s->operands[0] = INT_MIN;
		return (can_exit(s));
	}
	s->result = 0;
	return (can_exit(s));
}

BOOL	is_operand_expected(struct s_state state)
{
	if (!is_operand_0_set(state))
	{
		return (TRUE);
	}
	if (!is_operand_1_set(state) && is_operator_0_set(state))
	{
		return (TRUE);
	}
	if (!is_operand_2_set(state) && is_operator_1_set(state))
	{
		return (TRUE);
	}
	return (FALSE);
}

BOOL	is_right_parenthesis_expected(void)
{
	return (TRUE);
}

int		eval(struct s_state *state)
{
	int				operand;
	char			*str;
	struct s_state	new_state;

	print_state(*state);
	if (ready_to_calc(*state))
	{
		calc_5(state);
	}
	if (state->input.str == NULL || is_end_of_string_array(get_str(state)))
	{
		if (can_exit(state))
		{
			return (state->result);
		}
	}
	str = state->input.str[state->input.i];
	if (ft_strcmp(str, "(") == 0)
	{
		state->input.i++;
		new_state = get_new_state(state->input);
		operand = eval(&new_state);
		set_position(state, new_state.input.i);
		add_operand(operand, state);
		return (eval(state));
	}
	if (ft_strcmp(str, ")") == 0)
	{
		if (!is_right_parenthesis_expected())
		{
			ft_putstr("')' is not expected");
			state->result = INT_MIN;
		}
		state->input.i++;
		if (can_exit(state))
		{
			return (state->result);
		}
	}
	if (is_number(str))
	{
		operand = ft_atoi(str);
		add_operand(operand, state);
		state->input.i++;
		return (eval(state));
	}
	if (is_operand_expected(*state))
	{
		ft_putstr("int operand expected but found: '");
		ft_putstr(str);
		ft_putstr("'\n");
		return (INT_MIN);
		exit(1);
	}
	if (ft_strlen(str) != 1)
	{
		ft_putstr("operator expected but found: '%s'");
		ft_putstr(str);
		ft_putstr("'\n");
		exit(1);
	}
	add_operator(*str, state);
	state->input.i++;
	return (eval(state));
}

int		eval_expr(char *str)
{
	char			**splitted;
	int				len;
	struct s_state	state;
	struct s_input	input;

	if (!str || !*str)
	{
		return (0);
	}
	splitted =
		split_char(
			split_char(
				split(str, &len, " \t")
				, '(')
			, ')');
	input.str = splitted;
	input.i = 0;
	state = get_new_state(input);
	return (eval(&state));
}
