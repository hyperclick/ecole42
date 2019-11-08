/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_folder_entries.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:48:31 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:48:32 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

BOOL		need_to_show(t_entry e, t_find_options o)
{
	if (o.all)
	{
		return (TRUE);
	}
	if (ft_starts_with(e.full_name.name, '.'))
	{
		return (o.almost_all);
	}
	return (TRUE);
}

static DIR	*open_dir(const t_f_n fn)
{
	DIR		*dir;

	dir = opendir(fn.path);
	if (!dir)
	{
		log_line("diropen failed");
		log_line(fn.path);
		log_line(strerror(errno));
		ft_putstr_fd("ls: ", STDERR_FILENO);
		ft_putstr_fd(fn.name, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		return (NULL);
	}
	return (dir);
}

static int		count_entries(t_f_n fn)
{
	DIR				*dir;
	int				count;
	struct dirent	*entry;

	dir = open_dir(fn);
	if (dir == NULL)
	{
		return (0);
	}
	count = 0;
	while ((entry = readdir(dir)) != NULL)
	{
		count++;
	}
	closedir(dir);
	return (count);
}

static int	fill_entries(t_entry *new_entries, t_f_n fn, const t_find_options o)
{
	DIR				*dir;
	struct dirent	*entry;
	t_entry			e;
	int				i;
	char			path[PATH_MAX];
	size_t			directory_length;

	directory_length = ft_strlen(fn.path);
	ft_strcpy(path, fn.path);
	path[directory_length] = PATH_SEPARATOR;
	dir = open_dir(fn);
	i = 0;
	while ((entry = readdir(dir)) != NULL)
	{
		ft_strcpy(path + directory_length + 1, entry->d_name);
		e = try_get_entry(path);
		if (!is_null_entry(e) && need_to_show(e, o))
		{
			new_entries[i++] = e;
		}
	}
	closedir(dir);
	return (i);
}

int			get_folder_entries(
			t_entry **entries, t_entry folder, t_find_options o)
{
	t_entry			*new_entries;
	int				count;

	new_entries = NULL;
	count = count_entries(folder.full_name);
	if (count > 0)
	{
		new_entries = malloc(sizeof(t_entry) * count);
		count = fill_entries(new_entries, folder.full_name, o);
	}
	*entries = new_entries;
	return (count);
}
