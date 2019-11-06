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
	if (o.details)
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


char* formatdate(char* str, time_t val)
{
	char *str2;
	char *tmp;
	long i;
	time_t val2;
	char *tmp2;
	
	val2 = val;
	i = time(NULL);
	
	str2=ft_strncpy(&str[0], ctime(&val)+4, 4);
	str2=ft_strncpy(&str[4], ctime(&val)+8, 3);
	tmp2=ctime(&val)+20;
	if (i - val <= 15724800 && i - val >= 0)
	{
		str2=ft_strncpy(&str[7], ctime(&val)+11, 5);
		str[12]='\0';
	}
	else
	{
		if (val>=253402290000)
		{
			tmp2=ctime(&val)+23;
			//tmp = ft_strjoin(" ", tmp2);
			str2 = ft_strncpy(&str[7], tmp2, 7);
			//free(tmp);
			str[13]='\0';
		}
		else
		{
			tmp = ft_strjoin(" ", tmp2);
			str2 = ft_strncpy(&str[7], tmp, 5);
			free(tmp);
			str[12]='\0';
		}
	}
	
	return str;
}

BOOL	has_xattr(const char filename[])
{
	char list[XATTR_SIZE];
	ssize_t len;
	len = listxattr(filename, list, XATTR_SIZE, XATTR_NOFOLLOW);
	
	return (len > 0);
	
}

int		get_number_len(unsigned int number)
{
	int len = 0;
	while (number >= 10)
	{
		number /= 10;
		len++;
	}
	return (len);
}

void print_spaces(int sizespace)
{
	while (sizespace-- > 0)
		ft_putchar(' ');
}



void	print_details(t_entry e, int max_links_len, int max_size_len, int max_group_len, int max_user_len, BOOL any_has_xattr)
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
	else if(any_has_xattr)
	{
		ft_putchar(' ');
	}
	print_spaces(2 + get_number_len(max_links_len) - get_number_len(e.s.st_nlink));
	ft_putnbr( e.s.st_nlink);
	ft_putstr(" ");
	
	ft_putstr( getpwuid(e.s.st_uid)->pw_name);
	print_spaces(2 + max_user_len - ft_strlen(getpwuid(e.s.st_uid)->pw_name));
	
	ft_putstr( getgrgid(e.s.st_gid)->gr_name);
	print_spaces(max_group_len - ft_strlen(getgrgid(e.s.st_gid)->gr_name));
	
	print_spaces(2 + get_number_len(max_size_len) - get_number_len(e.s.st_size));
	ft_putnbr(e.s.st_size);
	ft_putstr(" ");
	char date[36];
	ft_putstr(formatdate(date, e.s.st_mtime));
	ft_putstr(" ");
}

char	*get_link_target(char *buf, const char *name)
{
	ssize_t len;
	if ((len = readlink(name, buf, sizeof(buf)-1)) != -1)
		buf[len] = '\0';
	else
		perror("readlink");
	return (buf);
}

static void print_link_target(const char name[])
{
	ft_putstr(" -> ");
	
	char buf[MAX_PATH];
	
	ft_putstr(get_link_target(buf, name));
}

void	print(t_entry e, t_print_options o, int  max_link_len, int max_size_len, int max_group_len, int max_user_len, BOOL any_has_xattr)
{
	if (o.details)
	{
		print_details(e, max_link_len, max_size_len, max_group_len, max_user_len, any_has_xattr);
	}
	
	ft_putstr(e.full_name.name);
	if (is_link(e.s.st_mode) && o.details)
	{
		print_link_target(e.full_name.path);
	}
	
}

int		find_max_link_len(t_entry	entries[MAX_FSO_IN_DIR], int count)
{
	int max = 0;
	for (int i = 0; i < count; i++)
	{
		if (max < entries[i].s.st_nlink)
		{
			max = entries[i].s.st_nlink;
		}
	}
	return (max);
}

int		find_max_size_len(t_entry	entries[MAX_FSO_IN_DIR], int count)
{
	int max = 0;
	for (int i = 0; i < count; i++)
	{
		if (max < entries[i].s.st_size)
		{
			max = entries[i].s.st_size;
		}
	}
	return (max);
}

size_t	find_max_group_len(t_entry	entries[MAX_FSO_IN_DIR], int count)
{
	size_t max = 0;
	for (int i = 0; i < count; i++)
	{
		if (max < ft_strlen(getgrgid(entries[i].s.st_gid)->gr_name))
		{
			max = ft_strlen(getgrgid(entries[i].s.st_gid)->gr_name);
		}
	}
	return (max);
}

size_t		find_max_user_len(t_entry	entries[MAX_FSO_IN_DIR], int count)
{
	size_t max = 0;
	for (int i = 0; i < count; i++)
	{
		if (max < ft_strlen(getpwuid(entries[i].s.st_uid)->pw_name))
		{
			max = ft_strlen(getpwuid(entries[i].s.st_uid)->pw_name);
		}
	}
	return (max);
}

size_t		does_any_have_xattr(t_entry	entries[MAX_FSO_IN_DIR], int count)
{
	while (count > 0)
	{
		if (has_xattr(entries[count--].full_name.path))
		{
			return (TRUE);
		}
	}
	return (FALSE);
}


void	print_entries(t_entry	entries[MAX_FSO_IN_DIR], int count, t_print_options o)
{
	BOOL	any_has_xattr = does_any_have_xattr(entries, count);
	int max_link_len = find_max_link_len(entries, count);
	int max_size_len = find_max_size_len(entries, count);
	int max_group_len= find_max_group_len(entries, count);
	int max_user_len= find_max_user_len(entries, count);
	if (count == 0)
	{
		return ;
	}
	int	cols_count = get_columns_count(entries, count, o);
	int	rows_count = get_rows_count(count, cols_count);
	for (int i = 0; i < rows_count; i++)
	{
		for (int j = 0; j < cols_count; j++)
		{
			print(entries[i * cols_count + j], o, max_link_len, max_size_len, max_group_len, max_user_len, any_has_xattr);
		}
		ft_putstr("\n");
	}
}

