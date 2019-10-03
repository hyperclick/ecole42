#define TESTS

#include <stdio.h>
#include "reader.h"
#include "assert.h"
#include "tetramino.h"
#include "result_checks.h"

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
	return (TRUE);
	return (t.letter == '1' && ft_strequ(r.path, "32"));
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

t_r	append_path(t_r r, t_elem letter)
{
	ft_str_append(r.path, letter);
	return (r);
}

t_r	append(t_r r, int row, int col, t_t	t)
{
	t_r new_r;

	new_r = append_path(r, t.letter);
	return (new_r);
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			new_r.a[row + i][col + j] = t.a[i][j];
		}
	}
	return (new_r);
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
	char	next_rest[27];
	t_r		new_r;


	len = ft_strlen(rest);
	if (len == 0)
	{
		r.found = is_square(r);
		return (r);
	}
	for (int n = 0; n < len; n++)
	{
		f = get_figure(rest[n]);
		for (int i = -3; i < r.height + 3; i++)
		{
			for (int j = -3; j < r.width + 3; j++)
			{
				if (can_append(r, i, j, f))
				{
					new_r = append(r, i, j, f);
					ft_strcpy(next_rest, rest);
					ft_str_remove_at(next_rest, n);
					new_r = fill(new_r, next_rest);
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

t_r	create_r(int width)
{
	t_r r;
	
	r.height = width;
	r.width = width;
	r.path[0] = 0;
	r.found = FALSE;
	r = r_fill_all(r, EMPTY_ELEM2);
	return (r);
}

void	test_fill(const char *file_name)
{
	t_list *lst = read_file(file_name);
	fill(create_r(ft_sqrt_up(ft_lst_count(lst) * 4)), "123");
	
	ft_lst_free(&lst);
}

t_r	test_stack(t_r r)
{
	r.height++;
	r.path[0]++;
	return r;
}

int main(int argc, const char * argv[])
{
	//t_r r2 = test_stack(create_r(4));
	
	
	test_valid_read("valid_sample.fillit");
	test_fill("valid_sample.fillit");
	
	
	
	
	printf("Hello, World1!\n");
	return 0;
}
