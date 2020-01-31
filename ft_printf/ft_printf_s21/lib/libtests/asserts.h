/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asserts.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERTS_H
#define ASSERTS_H
#include "libmem.h"

void	assert_int_equals(int e, int a);
void	assert_str_equals(const char *e, const char *a);
void	assert_is_null(void *p);
void	assert_is_not_null(void *p);
void	assert_true(BOOL b);
void	assert_false(BOOL b);
#endif 
