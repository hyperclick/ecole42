#include "reader.h"
#include <fcntl.h>
#include "../libft/libft.h"
#include "tetramino.h"
#include "tetramino_linq.h"
#include "result_checks.h"

#define BUFF_SIZE ((4 + 1)*(4) + 1) * sizeof(char)

BOOL	is_input_filled(t_elem e)
{
	return (e == FILLED_ELEM);
}

BOOL		is_neighbour_empty(t_t t, int row, int col)
{
	return (row < 0 || row > 4 - 1 || col < 0 || col > 4 - 1 || is_empty(t.a[row][col]));
}

BOOL		e_has_a_neighbour(t_t t, int row, int col)
{
	return
	(
	 !is_neighbour_empty(t, row, col - 1)
	 ||	!is_neighbour_empty(t, row, col + 1)
	 ||	!is_neighbour_empty(t, row - 1, col)
	 ||	!is_neighbour_empty(t, row + 1, col)
	 );
}

BOOL		e_has_diag_neighbour(t_t t, int row, int col)
{
	return
	(
	 (!is_neighbour_empty(t, row - 1, col - 1) && is_neighbour_empty(t, row, col - 1) && is_neighbour_empty(t, row - 1, col))
	 ||	(!is_neighbour_empty(t, row - 1, col + 1) && is_neighbour_empty(t, row - 1, col ) && is_neighbour_empty(t, row , col + 1))
	 ||	(!is_neighbour_empty(t, row + 1, col - 1) && is_neighbour_empty(t, row, col - 1) && is_neighbour_empty(t, row + 1, col))
	 ||	(!is_neighbour_empty(t, row + 1, col + 1) && is_neighbour_empty(t, row, col + 1) && is_neighbour_empty(t, row + 1, col))
	 );
}

BOOL		validate_adjacent(int lines[4])
{
	int	i;

	i = 0;
	while (++i < 4 - 1)
	{
		if (lines[i] == 0 && lines[i - 1] != 0 && lines[i + 1] != 0)
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

BOOL		validate_figure(t_t t)
{
	int	i;
	int	j;
	int	elements_count;
	int	filled_rows[4] = {0,0,0,0};
	int	filled_cols[4] = {0,0,0,0};

	elements_count = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!is_empty(t.a[i][j]))
			{
				if (!e_has_a_neighbour(t, i, j) || e_has_diag_neighbour(t, i, j))
				{
					return (FALSE);
				}
				elements_count++;
				filled_rows[i] = 1;
				filled_cols[j] = 2;
			}
			++j;
		}
		++i;
	}
	return (elements_count == 4 && validate_adjacent(filled_rows) && validate_adjacent(filled_cols));
}

BOOL		parse(t_t *dst, char str[BUFF_SIZE], char letter)
{
	t_t	t;
	int	i;
	int	j;

	t.letter = letter;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (is_empty(str[i * 5 + j]))
			{
				t.a[i][j] =  EMPTY_ELEM;
				continue;
			}
			if (!is_input_filled(str[i * 5 + j]))
			{
				return (FALSE);
			}
			t.a[i][j] = letter;
		}
		if (str[i * 5 + j] != '\n')
		{
			return (FALSE);
		}
	}
	if (str[i * 5] != '\n')
	{
		return (FALSE);
	}
	*dst = t;
	return (validate_figure(t));
}

BOOL	row_is_empty(t_t f, int row)
{
	int	j = -1;

	while (++j < 4)
	{
		if (!is_empty(f.a[row][j]))
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

BOOL	col_is_empty(t_t f, int col)
{
	int	i = -1;

	while (++i < 4)
	{
		if (!is_empty(f.a[i][col]))
		{
			return (FALSE);
		}
	}
	return (TRUE);
}


t_t		move_up(t_t f)
{
	int	i;
	int j;
	
	i = -1;
	while (++i < 4 - 1)
	{
		j = -1;
		while (++j < 4)
		{
			f.a[i][j] = f.a[i + 1][j];
		}
	}
	j = -1;
	while (++j < 4)
	{
		f.a[i][j] = EMPTY_ELEM;
	}
	return f;
}

t_t		move_left(t_t f)
{
	int	i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4 - 1)
		{
			f.a[i][j] = f.a[i][j + 1];
		}
	}
	i = -1;
	while (++i < 4)
	{
		f.a[i][j] = EMPTY_ELEM;
	}
	return f;
}

t_t		normalize(t_t f)
{
	while (row_is_empty(f, 0))
	{
		f = move_up(f);
	}
	while (col_is_empty(f, 0))
	{
		f = move_left(f);
	}
	return (f);
}

BOOL	is_bad_buffer(const char buffer[BUFF_SIZE], ssize_t bytes_read)
{
	if (bytes_read == BUFF_SIZE)
	{
		return (buffer[BUFF_SIZE - 1] != '\n');
	}
	return (bytes_read != BUFF_SIZE - 1);
}

t_t	*read_file(const char	*filename)
{
	int		fd;
	t_t		t;
	char	buffer[BUFF_SIZE];
	ssize_t	bytes_read;
	char	letter;
	BOOL	has_lf;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error\n");
		exit(1);
	}
	letter = 'A';
	set_figures_count(0);
	while ((bytes_read = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (is_bad_buffer(buffer, bytes_read) || parse(&t, buffer, letter) == FALSE)
		{
			ft_putstr("error\n");
			exit(2);
		}
		buffer[bytes_read] = 0;
		
		has_lf = buffer[bytes_read - 2] == '\n' && buffer[bytes_read - 1] == '\n';
		add_figure(normalize(t));
		++letter;
	}
	if (bytes_read != 0 || has_lf)
	{
		ft_putstr("error\n");
		exit(4);
	}
	return (g_figures);
}
