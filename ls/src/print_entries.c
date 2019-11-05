#include "ls.h"
#define SPACES_BETWEEN_COL 2
#include <time.h>

int	get_console_width()
{
	return (80);
}

int	get_all_letters(t_entry entries[], int entries_count)
{
	int	count;
	int	i;
	i = -1;
	count = 0;
	while (++i < entries_count)
	{
		count += ft_strlen(entries[i].full_name.name);
	}
	return (count);
}

int	get_rows_count(int entries_count, int cols_count)
{
	return (entries_count / cols_count);
}

int		get_col_width(t_entry entries[], int entries_count, int col, int rows_count)
{
	int start = col * rows_count;
	int	max_width = 0;
	int	width;
	int	i;
	
	i = start - 1;
	int count = MIN(start + rows_count, entries_count);
	while (++i < count)
	{
		if ((width = ft_strlen(entries[i].full_name.name)) > max_width)
		{
			max_width = width;
		}
	}
	return (max_width);
}

BOOL	can_print(t_entry entries[], int entries_count, int cols_count, int console_width)
{
	int	width;
	int	rows_count;
	int	i;

	rows_count = get_rows_count(entries_count, cols_count);

	i = -1;
	width = 0;
	while (++i < cols_count)
	{
		width += get_col_width(entries, entries_count, i, rows_count);
		if (i != cols_count - 1)
		{
			width += SPACES_BETWEEN_COL;
		}
		if (width > console_width)
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

int	get_columns_count(t_entry entries[], int entries_count, t_print_options o)
{
	return (1);
	if (o.details || o.single_column)
	{
		return (1);
	}
	int	all_letters = get_all_letters(entries, entries_count);
	int	max_spaces = entries_count - 1;
	int max_width = all_letters + max_spaces;
	int	console_width = get_console_width();
	if (console_width >= max_width)
	{
		return(entries_count);
	}
	int columns;
	columns = max_width / console_width;
	while (columns > 1)
	{
		if (can_print(entries, entries_count, columns, get_console_width()))
		{
			return (columns);
		}
		columns--;
	}
	return (1);
}

char* formatdate2(char* str, time_t val)
{
	strftime(str, 36, "%d.%m.%Y %H:%M:%S", localtime(&val));
	return str;
}
char* formatdate(char* str, time_t val)
{
	strftime(str, 36,  " %b\t%-d %H:%M", localtime(&val));
	return str;
}

BOOL	has_xattr(const char filename[])
{
	char list[XATTR_SIZE];
	ssize_t len;
	len = listxattr(filename, list, XATTR_SIZE, XATTR_NOFOLLOW);
	
	return (len > 0);
	
}

void	print_details(t_entry e)
{
	if (is_folder(e.s.st_mode))
	{
		ft_putchar('d');
	}
	if (is_link(e.s.st_mode))
	{
		ft_putchar('l');
	}
	switch (e.s.st_mode & S_IFMT)
	{
		case S_IFBLK:  ft_putchar('b');	break;
		case S_IFCHR:  ft_putchar('c');	break;
		case S_IFDIR:  	break;
		case S_IFIFO:  ft_putchar('p');	break;
		case S_IFLNK:  	break;
		case S_IFREG:  ft_putchar('-');	break;
		case S_IFSOCK: ft_putchar('s');	break;
		default:
			ft_putstr("unknown mode: ");
			ft_putnbr(e.s.st_mode);
			ft_putstr("\n");
			exit(2);
			break;
	}
	
	ft_putstr( (e.s.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr( (e.s.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr( (e.s.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr( (e.s.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr( (e.s.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr( (e.s.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr( (e.s.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr( (e.s.st_mode & S_IWOTH) ? "w" : "-");
	if (e.s.st_mode & S_ISVTX)
	{
		ft_putchar('t');
	}
	else
	{
		ft_putstr( (e.s.st_mode & S_IXOTH) ? "x" : "-");
	}
	if (has_xattr(e.full_name.path))
	{
		ft_putchar('@');
	}
	ft_putchar('\t');
	
	ft_putnbr( e.s.st_nlink);
	ft_putstr("\t");
	ft_putstr( getpwuid(e.s.st_uid)->pw_name);
	ft_putstr("\t");
	ft_putstr( getgrgid(e.s.st_gid)->gr_name);
	ft_putstr("\t");
	ft_putnbr(e.s.st_size);
	ft_putstr("\t");
	ft_putstr("\t");
	char date[36];
	ft_putstr(formatdate(date, e.s.st_mtime));
	ft_putstr("\t");
}

static void print_link_target(const char name[])
{
	ft_putstr(" -> ");
	
	char buf[1024];
	ssize_t len;
	
	if ((len = readlink(name, buf, sizeof(buf)-1)) != -1)
		buf[len] = '\0';
	else
		perror("readlink");
	ft_putstr(buf);
}

void	print(t_entry e, t_print_options o)
{
	if (o.details)
	{
		print_details(e);
	}
	ft_putstr( e.full_name.name);
	if (o.details && is_link(e.s.st_mode))
	{
		print_link_target(e.full_name.path);
	}
}

int		calc_total(t_entry	entries[MAX_FSO_IN_DIR], int count)
{
	int	total = 0;
	for (int j = 0; j < count; j++)
	{
		total += entries[j].s.st_blocks;
	}
	return (total);
}

void	print_entries(t_entry	entries[MAX_FSO_IN_DIR], int count, t_print_options o)
{
	if (count == 0)
	{
		return ;
	}
	if (o.details)
	{
		ft_putstr("total ");
		ft_putnbr( calc_total(entries, count));
		ft_putstr("\n");
	}
	int	cols_count = get_columns_count(entries, count, o);
	int	rows_count = get_rows_count(count, cols_count);
	for (int i = 0; i < rows_count; i++)
	{
		for (int j = 0; j < cols_count; j++)
		{
			print(entries[i * cols_count + j], o);
		}
		ft_putstr("\n");
	}
}
