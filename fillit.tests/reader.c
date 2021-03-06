#include "reader.h"
#include <fcntl.h>
#include "../libft/libft.h"
#include "tetramino.h"
#define BUFF_SIZE ((4 + 1)*(4) + 1) * sizeof(char)

t_t		*parse(char str[BUFF_SIZE], char letter)
{
	t_t	t;
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			t.letter = letter;
			t.a[i][j] = is_empty(str[i * 5 + j]) ? EMPTY_ELEM2 : letter;
			++j;
		}
		if (str[i * 5 + j] != '\n')
		{
			return (NULL);
		}
		++i;
	}
	if (str[i * 5] != '\n')
	{
		return (NULL);
	}
	return (&t);
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
		f.a[i][j] = EMPTY_ELEM2;
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
		f.a[i][j] = EMPTY_ELEM2;
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
	t_t		*t;
	t_list	*head;
	t_list	*next;
	t_list	*current;
	char	buffer[BUFF_SIZE];
	ssize_t	bytes_read;
	char	letter;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error\n");
		exit(1);
	}
	head = NULL;
	current = NULL;
	letter = 'A' - 1;
	g_figures_count = 0;
	while ((bytes_read = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (is_bad_buffer(buffer, bytes_read) || (t = (parse(buffer, ++letter))) == NULL)
		{
			ft_putstr("error\n");
			exit(2);
		}
		*t = normalize(*t);
		g_figures[g_figures_count++] = *t;
	}
	
	if (bytes_read != 0)
	{
		ft_putstr("error\n");
		exit(4);
	}
	
	return (g_figures);
}
