/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:47:40 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:47:42 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_entry	g_cur_dir;

void	set_cur_dir(const char *dir)
{
	g_cur_dir = try_get_entry(dir);
}

t_entry	get_cur_dir(void)
{
	return (g_cur_dir);
}
