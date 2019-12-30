/*_**************************************************************************_*/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asserts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/*_**************************************************************************_*/

#include "libft.h"
#include <stdio.h>
void assert_is_null(void *p)
{
	if (p!=NULL)
	{
		printf("assert failed: expected: NULL, actual: %p\n", p);
		exit(1);
	}
}
void assert_is_not_null(void *p)
{
	if (p==NULL)
	{
		printf("assert failed: expected: NOT NULL, actual: %p\n", p);
		exit(1);
	}
}
void assert_true(BOOL b)
{
	if (!b)
	{
		printf("assert failed: expected: TRUE, actual: FALSE\n");
		exit(1);
	}
}
void assert_false(BOOL b)
{
	if (b)
	{
		printf("assert failed: expected: FALSE, actual: TRUE\n");
		exit(1);
	}
}

void assert_int_equals(int e, int a)
{
	if (e != a)
	{
		printf("assert failed: expected: %d, actual: %d\n", e, a);
		exit(1);
	}
}

void assert_str_equals(const char* e, const char* a)
{
	if (!ft_strequ(e, a))
	{
		printf("assert failed: expected: '%s', actual: '%s'\n", e, a);
		exit(1);
	}
}