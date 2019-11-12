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

BOOL		is_folder(const mode_t mode)
{
	return (S_ISDIR(mode));
}

BOOL		is_link(const mode_t mode)
{
	return (S_ISLNK(mode));
}

BOOL		is_block_dev(const t_entry e)
{
	return (S_ISBLK(e.s.st_mode));
}

BOOL		is_char_dev(const t_entry e)
{
	return (S_ISCHR(e.s.st_mode));
}

BOOL		is_absolute_path(const char *path)
{
	return (*path == PATH_SEPARATOR);
}
