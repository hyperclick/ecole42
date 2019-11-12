/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:48:19 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:48:20 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

BOOL		is_cur_dir(const char name[])
{
	return (ft_strcmp(name, ".") == 0);
}

BOOL		is_parent_dir(const char name[])
{
	return (ft_strcmp(name, "..") == 0);
}
