#define TESTS

#include <stdio.h>
#include "reader.h"
#include "assert.h"
#include "tetramino.h"
#include "result_checks.h"

t_list *g_list = NULL;

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

BOOL	find_by_name(t_list *list, void *param)
{
	t_elem	e;
	t_t		*f;

	f = (t_t*)list->content;
	e = *((t_elem*)(param));
	return (f->letter == e);
}


t_t	get_figure(char letter)
{
	t_t *figure;

	figure = (t_t*)ft_lst_find(g_list, &letter, find_by_name)->content;
	return (*figure);
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
			//for (int i = 0; i < 2; i++)
		{
			for (int j = -3; j < r.width + 3; j++)
				//for (int j = 0; j < 1; j++)
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

t_t		extract_figure(t_list *list)
{
	return (*(t_t*)(list->content));
}

char	*make_rest(char *rest)
{
	char	*start;
	t_t		f;
	t_list	*list;

	start = rest;
	list = g_list;
	while (list!=NULL)
	{
		f = extract_figure(list);
		*rest = f.letter;
		rest++;
		list = list->next;
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

	g_list = read_file(file_name);
	width = ft_sqrt_up(ft_lst_count(g_list) * 4);
	max_width = width + 12;
	r.found = FALSE;
	while (width < max_width && r.found == FALSE)
	{
		r = fill(r = create_r(width), make_rest(rest));
		width++;
	}
	//assert_str("4321", r.path);
	
	ft_lst_free(&g_list);
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
