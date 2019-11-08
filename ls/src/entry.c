/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:48:19 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:48:20 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

BOOL	is_folder(const mode_t mode)
{
	return (S_ISDIR(mode));
}

BOOL	is_link(const mode_t mode)
{
	return (S_ISLNK(mode));
}

BOOL	is_absolute_path(const char *path)
{
	return (*path == PATH_SEPARATOR);
}

BOOL	is_null_entry(t_entry e)
{
	return (e.is_null);
}

t_entry	create_null_entry(void)
{
	t_entry	e;

	e.is_null = TRUE;
	return (e);
}

void	make_path(char *path, const char name[])
{
	if (ft_strlen(name) > MAX_PATH)
	{
		ft_putstr_fd("too long name\n", STDERR_FILENO);
		exit(1);
	}
	if (is_absolute_path(name))
	{
		ft_strcpy(path, name);
	}
	else
	{
		ft_strcpy(path, "./");
		ft_strcpy(path + 2, name);
	}
}

t_f_n	get_full_name(const char name[])
{
	t_f_n	fn;
	int		pos;
	int		len;
	char*	sub;

	fn = create_full_name();
	ft_strcpy(fn.path, name);
	if (ft_strcmp(".", name) == 0)
	{
		ft_strcpy(fn.name,".");
		return (fn);
	}
	pos = ft_last_index(fn.path, PATH_SEPARATOR);
	sub = ft_strsub(fn.path, 0, pos);
	if (sub != NULL)
	{
		free(sub);
	}
	pos++;
	len = ft_strlen(fn.path);
	sub = ft_strsub(name, pos, len - pos);
	if (sub != NULL)
	{
		ft_strcpy(fn.name, sub);
		free(sub);
	}
	return (fn);
}

void	fill_entry(t_entry* e, struct stat s, const char name[])
{
	e->s = s;
	e->full_name = get_full_name(name);
	e->is_null = FALSE;
}

t_entry	try_get_entry(const char arg[])
{
	t_entry		e;
	struct stat	s;

	e = create_null_entry();
	if (lstat(arg, &s) != -1)
	{
		fill_entry(&e, s, arg);
	}
	else
	{
		log_line("lstat failed:");
		log_line(arg);
		log_line(strerror(errno));
	}
	return (e);
}

t_entry	try_get_target_entry(const char link_path[])
{
	t_entry	e;
	char target_path[MAX_PATH];
	struct stat s;

	e = create_null_entry();
	if (stat(get_link_target(target_path, link_path, MAX_PATH), &s) != -1)
	{
		fill_entry(&e, s, target_path);
	}
	else
	{
		log_line("stat failed:");
		log_line(target_path);
		log_line(strerror(errno));
	}
	return (e);
}
