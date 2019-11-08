/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:48:19 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:48:20 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

BOOL		is_null_entry(t_entry e)
{
	return (e.is_null);
}

t_entry		create_null_entry(void)
{
	t_entry	e;

	e.is_null = TRUE;
	return (e);
}
