#include "ls.h"
#define SPACES_BETWEEN_COL 2

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
		count += strlen(entries[i].full_name.name);
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

	for (int i = start; i < MIN(start + rows_count, entries_count); i++)
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
	if (o.one_file_per_line)
	{
		return (1);
	}
	int	all_letters = get_all_letters(entries, entries_count);
	int	max_spaces = entries_count * 2;
	int max_width = all_letters + max_spaces;
	int	console_width = get_console_width();
	if (console_width >= max_width)
	{
		return(entries_count);
	}
	int columns;
	columns = max_width / console_width;
	while (columns > 0)
	{
		if (can_print(entries, entries_count, columns, get_console_width()))
		{
			return (columns);
		}
		columns--;
	}
	return (1);
}


void	print_details(t_entry e)
{
//	print_access_rights(e);

}

void	print(t_entry e, t_print_options o)
{
	if (o.one_file_per_line)
	{
		print_details(e);
	}
	printf("%s ", e.full_name.name);
	if (e.is_folder)
	{
		putchar(PATH_SEPARATOR);
	}
}

void		print_entries(t_entry	entries[MAX_FSO_IN_DIR], int count, t_print_options o)
{
	int	cols_count = get_columns_count(entries, count, o);
	int	rows_count = get_rows_count(count, cols_count);
	for (int i = 0; i < rows_count; i++)
	{
		for (int j = 0; j < cols_count; j++)
		{
			print(entries[i * cols_count + j], o);
		}
		printf("\n");
	}
}
