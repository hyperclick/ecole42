#include "ls.h"

BOOL	is_absolute_path(char	*path)
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
	int		len;

	len = 0;
	if (!is_absolute_path(name))
	{
		ft_strcpy(path, get_cur_dir().full_name.path);
		len = ft_strlen(path);
		path[len] = PATH_SEPARATOR;
		len++;
	}
	//todo: check overflow
	ft_strcpy(path + len, name);
}

t_f_n	get_full_name(const char name[])
{
	t_f_n	fn;
	int		pos;
	int		len;
	
	fn = create_full_name();
	make_path(fn.path, name);
	
	pos = ft_last_index(fn.path, PATH_SEPARATOR);
	len = ft_strlen(fn.path);
	char* sub = ft_strsub(fn.path, 0, pos);
	if (sub != NULL)
	{
		ft_strcpy(fn.folder, sub);
		free(sub);
	}
	pos++;
	sub = ft_strsub(name, pos, len - pos);
	if (sub != NULL)
	{
		ft_strcpy(fn.name, sub);
		free(sub);
	}
	return (fn);
}
/*
time_t	fill_mod_time(t_entry *e, struct stat s)
{
	
}
*/
void	fill_entry_shared(t_entry *e, struct stat s, const char name[])
{
	e->full_name = get_full_name(name);
	e->creation_time = s.st_ctime;
	e->access_time = s.st_atime;
	e->mod_time = s.st_mtime;
	e->size = s.st_size;
	e->is_null = FALSE;
}

void	fill_entry_dir(t_entry* e, struct stat s, const char name[])
{
	e->is_folder = TRUE;
	fill_entry_shared(e, s, name);
}

void	fill_entry_file(t_entry* e, struct stat s, const char name[])
{
	e->is_folder = FALSE;
	fill_entry_shared(e, s, name);
}

void	fill_entry_sym_link(t_entry* e, struct stat s, const char name[])
{
	e->is_folder = FALSE;
	fill_entry_shared(e, s, name);
}

void fill_entry(t_entry* e, struct stat s, const char name[])
{

	switch (s.st_mode & S_IFMT) {
	case S_IFBLK:  printf("block device:\tignoring\n");            break;
	case S_IFCHR:  printf("character device\tignoring\n");        break;
	case S_IFDIR:  fill_entry_dir(e, s, name);          break;
	case S_IFIFO:  printf("FIFO/pipe\tignoring\n");               break;
	case S_IFLNK:  fill_entry_sym_link(e, s, name);                 break;
	case S_IFREG:  fill_entry_file(e, s, name);           break;
	case S_IFSOCK: printf("socket\tignoring\n");                  break;
	default:       printf("unknown?: %d\n", s.st_mode);   exit(2);             break;
	}


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
		perror("lstat() ");
	}
	return (e);
}
