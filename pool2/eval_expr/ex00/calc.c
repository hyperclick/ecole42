/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:14:53 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 21:14:56 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"
#include "includes/state.h"

int		calc(int a, char *operator, int b)
{
	operator = "";
	return (a + b);
}

int		calc_3(int a, char operator, int b)
{
	if (operator == '+')
	{
		return (a + b);
	}
	if (operator == '-')
		return (a - b);
	if (operator == '*')
		return (a * b);
	if (operator == '/')
		return (a / b);
	if (operator == '%')
		return (a % b);
	ft_putstr("undefined operator: ");
	ft_putchar(operator);
	ft_putchar('\n');
	exit(1);
}

int		get_precedence(char operator)
{
	if (operator == '+')
		return (1);
	if (operator == '-')
		return (1);
	if (operator == '*')
		return (2);
	if (operator == '/')
		return (2);
	if (operator == '%')
		return (2);
	ft_putstr("undefined operator: ");
	ft_putchar(operator);
	ft_putchar('\n');
	exit(1);
}

int		cmp_operators(char a, char b)
{
	return (get_precedence(a) - get_precedence(b));
}

void	calc_5(struct s_state *state)
{
	int r;

	if ((cmp_operators(state->operators[0], state->operators[1])) >= 0)
	{
		print_state(*state);
		r = calc_3(state->operands[0], state->operators[0], state->operands[1]);
		state->operands[0] = r;
		state->operators[0] = state->operators[1];
		state->operands[1] = state->operands[2];
		state->operators[1] = '?';
		state->operands[2] = INT_MIN;
	}
	else
	{
		print_state(*state);
		r = calc_3(state->operands[1], state->operators[1], state->operands[2]);
		state->operands[1] = r;
		state->operators[1] = '?';
		state->operands[2] = INT_MIN;
	}
	print_state(*state);
}
