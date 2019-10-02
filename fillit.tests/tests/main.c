#define TESTS

#include <stdio.h>
#include "reader.h"
#include "assert.h"
#include "tetramino.h"

void	test_valid_read(const char *file_name)
{
	t_list *list = read_file(file_name);
	assert_int(4, ft_lst_count(list));
	ft_lst_free(&list);
}
const	int found = 1;
const	int figures_finished = 2;
const	int	all_rows_filled = 3;

BOOL	is_out_of_square(t_r r, int row, int col)
{
	return (row < 0 || col < 0 || row >= r.height || col >= r.width);
}

BOOL	is_empty(t_elem t)
{
	return (t == empty_elem);
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
	return (t.letter == '1' && ft_strcmp(r.path, "32"));
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
			if (has_a_neighbour(r, row + i, col + j))
			{
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

void	append(t_r *r, int row, int col, t_t	t)
{
	append_path(r, t.letter);
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			r->a[row + i][col + j] = t.a[i][j];
		}
	}
}



BOOL	is_square(t_r r)
{
	return (ft_strcmp("321", r.path));
}
t_t	get_figure(char letter)
{
	t_t figure;
	
	figure.letter = letter;
	return (figure);
}

t_r		fill(t_r r, const char rest[])
{
	size_t	len;
	t_t	f;
	char	next_rest[26];
	t_r		new_r;

	len = ft_strlen(rest);
	if (len == 0)
	{
		r.found = is_square(r);
		return (r);
	}
	for (int i = 0; i < len; i++)
	{
		f = get_figure(rest[i]);
		for (int i = -3; i < r.height + 3; i++)
		{
			for (int j = -3; j < r.width + 3; j++)
			{
				if (can_append(r, i, j, f))
				{
					append(&r, i, j, f);
					ft_strcpy(next_rest, rest);
					ft_str_remove_at(next_rest, i);
					new_r = fill(r, next_rest);
					if (new_r.found)
					{
						return (new_r);
					}
				}
			}
		}
	}
	return (r);
}



void	test_fill(const char *file_name)
{
	t_list *list = read_file(file_name);
	t_r r;
	fill(r, "123");
	
	ft_lst_free(&list);
}

int main(int argc, const char * argv[])
{
	test_valid_read("valid_sample.fillit");
	test_fill("valid_sample.fillit");
	
	
	
	
	printf("Hello, World1!\n");
	return 0;
}
