#include "ls.h"

BOOL    need_to_show(t_entry e, t_find_options o)
{
	if (o.all)
	{
		return (TRUE);
	}
	if (ft_starts_with(e.full_name.path, '.'))
	{
		return (o.almost_all);
	}
	return (TRUE);
}

int		get_folder_entries(t_entry entries[], t_entry folder, t_find_options o)
{
	t_entry e;
	e = folder;
	DIR* dir;
	struct dirent* entry;
	dir = opendir(folder.full_name.path);
	if (!dir)
	{
		//todo: compare with ls output
		//todo: set exit_code = 1
		ft_putstr(folder.full_name.path);
		ft_putstr("\n");
		perror("diropen");
		return 0;
	};

	size_t directory_length = strlen(folder.full_name.path);
	char path[NAME_MAX];
	strcpy(path, folder.full_name.path);
	path[directory_length] = PATH_SEPARATOR;
	int i = 0;
	while ((entry = readdir(dir)) != NULL)
	{
		strcpy(path + directory_length + 1, entry->d_name);
		e = try_get_entry(path);
		if (!is_null_entry(e) && need_to_show(e, o))
		{
			entries[i++] = e;
		}
		//free(entry);???
	};

	closedir(dir);
	//free(dir);???
	return (i);
}
