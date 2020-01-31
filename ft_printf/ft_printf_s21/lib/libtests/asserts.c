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

#include <stdlib.h>
#include "ft_printf.h"
#include "libstr.h"

void	assert_int_equals(int e, int a)
{
	if (e != a)
	{
		ft_printf("assert failed: expected: %d, actual: %d\n", e, a);
		exit(1);
	}
}

void	assert_str_equals(const char *e, const char *a)
{
	if (!ft_strequ(e, a))
	{
		ft_printf("assert failed: expected: '%s', actual: '%s'\n", e, a);
		exit(1);
	}
}
