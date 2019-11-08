#include "ls.h"

BOOL	need_to_show(t_entry e, t_find_options o)
{/*
	if (ft_strcmp(e.full_name.name, ".") || ft_strcmp(e.full_name.name, "..") )
	{
		return (false);
	}*/
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

int		get_folder_entries(t_entry **entries, t_entry folder, t_find_options o)
{
	t_entry *new_entries = NULL;
	t_entry e;
	e = folder;
	DIR* dir;
	struct dirent* entry;
	dir = opendir(folder.full_name.path);
	if (!dir)
	{
		log_line("diropen failed");
		log_line(folder.full_name.path);
		log_line(strerror(errno));
		ft_putstr_fd("ls: ", STDERR_FILENO);
		ft_putstr_fd(folder.full_name.path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		return 0;
	};

	size_t directory_length = ft_strlen(folder.full_name.path);
	char path[PATH_MAX];
	ft_strcpy(path, folder.full_name.path);
	path[directory_length] = PATH_SEPARATOR;
	int count = 0;
	while ((entry = readdir(dir)) != NULL)
	{
		//ft_strcpy(path + directory_length + 1, entry->d_name);
		//e = try_get_entry(path);
		//if (!is_null_entry(e) && need_to_show(e, o))
		{
			count++;
		}
		//free(entry);???
	};
	closedir(dir);
	dir = opendir(folder.full_name.path);
	new_entries = malloc(sizeof(t_entry) * count);
	int i = 0;
	while ((entry = readdir(dir)) != NULL)
	{
		ft_strcpy(path + directory_length + 1, entry->d_name);
		e = try_get_entry(path);
		if (!is_null_entry(e) && need_to_show(e, o))
		{
			new_entries[i++] = e;
		}
		//free(entry);???
	};

	closedir(dir);
	//free(dir);???
	
	*entries = new_entries;
	return (i);
}
