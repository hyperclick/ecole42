/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:29:04 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:29:06 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_last_row(t_table* t)
{
	return (t->height - 1);
}

int		get_last_col(t_table* t)
{
	return (t->width - 1);
}

t_coord	get_coord_by_offset(t_table* t, int offset)
{
	t_coord c;

	c.row = offset / t->width;
	c.col = offset  % t->width;
	//debug_printf("t->active_index = %d, t->width = %d, c.row = %d, c.col = %d\n",t->active_index, t->width, c.row, c.col);
	return (c);
}

t_coord	get_active_cell_coord(t_table* t)
{
	return (get_coord_by_offset(t, get_active_cell_offset()));
}

int	get_offset(t_table* t, int row, int col)
{
	return (row * t->width + col);
}

BOOL		is_out_of_table2(t_table* t, int offset)
{
	return (offset > t->cells_count - 1);
}

BOOL		is_out_of_table(t_table* t, int row, int col)
{
	return (is_out_of_table2(t, get_offset(t, row, col)));
}

char* get_cell(t_table* t, int row, int col)
{
	int offset;

	offset = get_offset(t, row, col);
	if (is_out_of_table2(t, offset))
	{
		return (NULL);
	}
	//debug_printf("get cell: row= %d, col = %d, offset = %d, cell = '%s', t->cells_count = %d\n", row, col, offset, t->cells[offset], t->cells_count);
	if (t->cells[offset] == NULL)
	{
		ft_printf("smth wrong\n");
		ft_exit(1);
	}
	return (t->cells[offset]);
}

BOOL		is_empty(const char* cell)
{
	return cell == NULL;
}

int	get_max_col_width(t_table* t, int c)
{
	int	i;
	int max;
	int width;
	char* cell;

	max = 0;
	i = -1;
	while (++i < t->height)
	{
		cell = get_cell(t, i, c);
		if (is_empty(cell))
		{
			continue;
		}
		width = ft_strlen(cell);
		if (max < width)
		{
			max = width;
		}
	}
	return (max);
}

void	fill_max_col_width(t_table* t)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	while (++i < t->width)
	{
		t->col_widths[++j] = get_max_col_width(t, i) + 1;
	}
	t->col_widths[j] --;//substract last space
}

int	sum_array(int cols[], int size)
{
	int	sum;

	sum = 0;
	while (size-- > 0)
	{
		sum += cols[size];
	}
	return (sum);
}

int	get_width_to_print(t_table* t)
{
	t->col_widths = (int*)malloc(sizeof(int) * t->width);
	fill_max_col_width(t);
	t->printed_width = sum_array(t->col_widths, t->width);
	debug_printf("t->printed_width = %d\n", t->printed_width);
	return (t->printed_width);
}


t_table* try_table(t_table* t)
{
	if (get_width_to_print(t) <= g_size_current.ws_col)
	{
		return (t);
	}
	else
	{
		g_table = t;
		free_table();
		return (NULL);
	}
}


void		fill_cells(t_table* t, char** src)
{
	t->cells = src;
	t->cells_count = ft_count_null_term_array((void**)src);
	/*return;
	int count;
	int i;
	int j;

	while (*src != NULL)
	{
		*(t->cells)++ = *src++;
	}
	return;
	count = ft_count_null_term_array((void**)src);
	i = -1;
	while (++i < t->height)
	{
		j = -1;
		while (++j < t->width)
		{
			t->cells[i * t->width + j] = src[i * t->width + j];
		}
	}*/
}

void free_table()
{
	if (g_table != NULL)
	{
		//		ft_free_array((void**)g_table->cells, g_table->height * g_table->width);
		free(g_table->col_widths);
		//free(g_table->selected);
		free(g_table);
		g_table = NULL;
	}
}

t_table* fill_table(int rows, int cols)
{
	t_table* t;

	t = (t_table*)malloc(sizeof(t_table));
	t->height = rows;
	t->width = cols;
	//t->cells = (char**)malloc(sizeof(char*) * rows * cols);
	//t->active_index = -1;
	fill_cells(t, g_options);
	debug_printf("table (h:%d, w:%d) created\n", t->height, t->width);
	return(t);
}


t_table* try_cols(int cols)
{
	int count;
	int rows;

	debug_printf("try_cols: %d\n", cols);
	count = ft_count_null_term_array((void**)g_options);
	rows = 0;
	while (rows * cols < count)
	{
		rows++;
	}

	if (rows == 0)
	{
		return (NULL);
	}
	return (try_table(fill_table(rows, cols)));
}

char* fill_spaces(char* str, int n)
{
	while (n-- > 0)
	{
		*str++ = '_';
	}
	return (str);
}
# define DEFAULT_COLOR			"\033[0m"
# define A_COLOR				"\033[31m"
# define REVERSE_VIDEO_COLOR		"\033[7m"
# define UNDERLINED				"\033[4m"

char* fill_table_cell(char* str, t_table* t, int i, int j)
{
	char* cell;
	int		cell_len;
	int		spaces;

	cell = get_cell(t, i, j);
	cell_len = ft_strlen(cell);
	if (is_active(t, i, j))
	{
		ft_strcpy(str, UNDERLINED);
		str += ft_strlen(UNDERLINED);
	}
	if (is_selected(t, i, j))
	{
		ft_strcpy(str, REVERSE_VIDEO_COLOR);
		debug_printf("selected: (%d, %d): '%s'\n",i, j, str);
		str += ft_strlen(REVERSE_VIDEO_COLOR);
	}
	ft_strcpy(str, cell);
	str += cell_len;

	ft_strcpy(str, DEFAULT_COLOR);
	str += ft_strlen(DEFAULT_COLOR);
	spaces = t->col_widths[j] - cell_len;
	str = fill_spaces(str, spaces);
	return (str);
}

void		fill_table_string(char* str, t_table* t)
{
	int	i;
	int	j;

	i = -1;
	while (++i < t->height)
	{
		j = -1;
		while (++j < t->width)
		{
			if (is_out_of_table(t, i, j))
			{
				*str = 0;
				return;
			}
			str = fill_table_cell(str, t, i, j);
		}
		*str = '\n';
		str++;
	}
	if (*(str - 1) == '\n')
	{
		str--;
	}
	debug_printf("str - 1 = '%c'\n", *(str - 1));
	if (*(str - 1) == '_')
	{
		str--;
	}
	*str = 0;
}
void		fill_table_string2(char* str, t_table* t)
{
	int	i;
	int	j;

	i = -1;
	while (++i < t->height)
	{
		j = -1;
		while (++j < t->width)
		{
			if (is_out_of_table(t, i, j))
			{
				//debug_printf("i:%d, j:%d, sum(0:%d) = %d spaces\n", i, j, j, sum_array(t->col_widths, j));
				//debug_printf("i:%d, j:%d, want to fill %d spaces\n", i, j, g_size_current.ws_col - sum_array(t->col_widths, j));
				//str = fill_spaces(str, g_size_current.ws_col - sum_array(t->col_widths, j));
				*str = 0;
				return;
			}
			str = fill_table_cell(str, t, i, j);
		}
		str = fill_spaces(str, g_size_current.ws_col - t->printed_width);
		*str = '\n';
		str++;
	}
	if (*(str - 1) == '\n')
	{
		str--;
	}
	debug_printf("str - 1 = '%c'\n", *(str - 1));
	if (*(str - 1) == '_')
	{
		str--;
	}
	*str = 0;
}

char* table_to_string(t_table* t)
{
	char* r;
	int	size;

	size = t->height + t->height * g_size_current.ws_col + 1 + ft_count_null_term_array((void**)g_options)*6*6;
	r = (char*)malloc(sizeof(char) * size);
	debug_printf("%d allocated for table string(%d + %d * %d + 1)\n", size, t->height, t->height, g_size_current.ws_col);
	//r[t->height * t->printed_width] = 0;
	fill_table_string2(r, t);
	return (r);
}
