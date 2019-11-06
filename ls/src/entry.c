#include "ls.h"

BOOL	is_folder(const mode_t mode)
{
	return (S_ISDIR(mode));
}

BOOL	is_link(const mode_t mode)
{
	return (S_ISLNK(mode));
}

BOOL	is_absolute_path(const char	*path)
{
	return (*path == PATH_SEPARATOR);
}

BOOL	is_null_entry(t_entry e)
{
	return (e.is_null);
}

t_entry	create_null_entry()
{
	t_entry e;
	e.is_null = TRUE;
	return (e);
}

void	make_path(char *path, const char name[])
{
	if (is_absolute_path(name))
	{
		//todo: check overflow
		ft_strcpy(path, name);
	}
	else
	{
		ft_strcpy(path, "./");
		//todo: check overflow
		ft_strcpy(path + 2, name);
	}
}

t_f_n	get_full_name(const char name[])
{
	t_f_n	fn;
	int		pos;
	int		len;
	
	fn = create_full_name();
	ft_strcpy(fn.path, name);
	if (ft_strcmp(".", name) == 0)
	{
		//ft_strcpy(fn.path, ".");
		ft_strcpy(fn.folder, ".");
		ft_strcpy(fn.name,".");
		return (fn);
	}
	
	//make_path(fn.path, name);
	
	pos = ft_last_index(fn.path, PATH_SEPARATOR);
	char* sub = ft_strsub(fn.path, 0, pos);
	if (sub != NULL)
	{
		ft_strcpy(fn.folder, sub);
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


void fill_entry(t_entry* e, struct stat s, const char name[])
{
	e->s = s;
	e->full_name = get_full_name(name);
	e->is_null = FALSE;
	/*
	if (is_link(s.st_mode))
	{
		struct stat ls;
		if (stat(name, &ls) == -1)
		{
			perror("stat()");
		}
		e->ls = ls;
	}*/
}

t_entry try_get_entry(const char arg[])
{
	t_entry e;
	e = create_null_entry();

	struct stat s;
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


t_entry try_get_target_entry(const char link_path[])
{
	t_entry e;
	e = create_null_entry();
	
	char target_path[MAX_PATH];
	struct stat s;
	if (stat(get_link_target(target_path, link_path), &s) != -1)
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

