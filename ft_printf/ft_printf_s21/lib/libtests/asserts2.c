/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asserts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"
#include "ft_printf.h"

void	assert_is_null(void *p)
{
	if (p != NULL)
	{
		ft_printf("assert failed: expected: NULL, actual: %p\n", p);
		exit(1);
	}
}

void	assert_is_not_null(void *p)
{
	if (p == NULL)
	{
		ft_printf("assert failed: expected: NOT NULL, actual: %p\n", p);
		exit(1);
	}
}

void	assert_true(BOOL b)
{
	if (!b)
	{
		ft_printf("assert failed: expected: TRUE, actual: FALSE\n");
		exit(1);
	}
}

void	assert_false(BOOL b)
{
	if (b)
	{
		ft_printf("assert failed: expected: FALSE, actual: TRUE\n");
		exit(1);
	}
}
