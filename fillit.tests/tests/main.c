#define TESTS

#include <stdio.h>
#include "reader.h"
#include "assert.h"
#include "tetramino.h"
#include "result_checks.h"

void	test_valid_read(const char *file_name)
{
	read_file(file_name);
	int q = g_figures_count;
	assert_int(4, q);
}
const	int found = 1;
const	int figures_finished = 2;
const	int	all_rows_filled = 3;

BOOL	is_out_of_square(t_r r, int row, int col)
{
	return (row < 0 || col < 0 || row >= r.height || col >= r.width);
}

BOOL	is_overlap(t_r r, int row, int col)
{
	return (!is_empty(r.a[row][col]));
}

BOOL	has_a_neighbour(t_r r, int row, int col)
{
	return (row == 0 || col == 0 || row == r.height - 1 || col == r.width - 1);
}

BOOL	can_append(t_r r, int row, int col, t_t t)
{
	BOOL	has_neighbour;
	
	has_neighbour = FALSE;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (is_empty(t.a[i][j]))
			{
				continue;
			}
			if (is_out_of_square(r, row + i, col + j))
			{
				return (FALSE);
			}
			if (is_overlap(r, row + i, col + j))
			{
				return (FALSE);
			}
			if (!has_neighbour && has_a_neighbour(r, row + i, col + j))
			{
				has_neighbour = TRUE;
			}
		}
	}
	return (has_neighbour);
}

t_r	append_path(t_r r, t_elem letter)
{
	ft_str_append(r.path, letter);
	return (r);
}

void	print_r(t_r r)
{
	int	i;
	int	j;

	i = 0;
	while (i < r.height)
	{
		j = 0;
		while (j < r.width)
		{
			ft_putchar(r.a[i][j]);
			++j;
		}
		ft_putchar('\n');
		++i;
	}
}

t_r	append(t_r r, int row, int col, t_t	t)
{
	t_r new_r;

	new_r = append_path(r, t.letter);
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (!is_empty(t.a[i][j]) && !is_out_of_square(r, row + i, col + j))
			{
				new_r.a[row + i][col + j] = t.a[i][j];
			}
		}
	}
	return (new_r);
}

t_t	get_figure(char letter)
{
	return (g_figures[letter - 'A']);
}

t_r		fill(t_r r, const char rest[])
{
	size_t	len;
	t_t	f;
	char	next_rest[27];
	t_r		new_r;
	BOOL	appended;

	r.deep++;
	len = ft_strlen(rest);
	if (len == 0)
	{
		r.found = TRUE; //is_square(r);
		return (r);
	}
	for (int n = 0; n < len; n++)
	{/*
		printf("\r");
		for (int deep = 0; deep < r.deep; deep++)
		{
			printf(" ");
		}
		printf("path: %s rest: %s check %c", r.path, rest, rest[n]);
	  */
		f = get_figure(rest[n]);
		appended = FALSE;
		for (int i = -3; i < r.height + 3; i++)
		{
			for (int j = -3; j < r.width + 3; j++)
			{/*
				if (r.deep < 4)
				{
					printf("\r");
					for (int deep = 0; deep < r.deep; deep++)
					{
						printf(" ");
					}
					printf("path: %s rest: %s check %c i:%d j:%d", r.path, rest, rest[n], i, j);
					
				}*/
				if (can_append(r, i, j, f))
				{
					appended = TRUE;
					//print_r(r);
					new_r = append(r, i, j, f);
					ft_strcpy(next_rest, rest);
					ft_str_remove_at(next_rest, n);
					printf("appended: path: %s next_rest: %s   i:%d j:%d\n", new_r.path, next_rest,  i, j);
					print_r(new_r);
					ft_putchar('\n');
					new_r = fill(new_r, next_rest);
					if (new_r.found)
					{
						return (new_r);
					}
				}
			}
		}
		if (!appended)
		{
			return (r);
		}
	}
	return (r);
}

t_r	create_r(int width)
{
	t_r r;
	
	r.height = width;
	r.width = width;
	r.path[0] = 0;
	r.found = FALSE;
	r.deep = 0;
	r = r_fill_all(r, EMPTY_ELEM2);
	return (r);
}
 
char	*make_rest(char *rest)
{
	int		i;
	char	*start;

	start = rest;
	i = -1;
	while (++i < g_figures_count)
	{
		*rest = g_figures[i].letter;
		rest++;
	}
	*rest = 0;
	return (start);
}

void	test_fill(const char *file_name)
{
	char	rest[27];
	int		width;
	int		max_width;
	t_r		r;

	read_file(file_name);
	width = ft_sqrt_up(g_figures_count * 4);
	max_width = width + 12;
	r.found = FALSE;
	while (width < max_width && r.found == FALSE)
	{
		r = fill(r = create_r(width), make_rest(rest));
		width++;
	}
}



int main(int argc, const char * argv[])
{
	test_valid_read("valid_sample.fillit");
	test_fill("valid_sample.fillit");
	
	
	
	
	printf("Hello, World1!\n");
	return 0;
}
