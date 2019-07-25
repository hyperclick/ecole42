#include "../includes/ft.h"
#include "../includes/t_table.h"
#include "../includes/file_processor.h"

char		g_tmp[100];
int		g_lines_read;
//int		g_lines_len;

t_table	*g_first_candidate = NULL;

void	print_table(char *caption, t_table *table)
{
	ft_putstr(caption);
	new_line();
	table_print_header();
	table_print_all(table);
	new_line();
}

t_table	*create_all_candidates(t_table **table, int x, int len, int *r)
{
	int		i;
	t_section	data;

	if (len == 0)
		return (*table);
	i = get_bsq().len + 1;
	while (i <= len)
	{
		data.x = x;
		data.y = g_lines_read;
		data.len = i;
		*table = table_append(table, data);
		if (*table == NULL)
		{
			*r = -1;
			_log("failed to append data\n");
			return (NULL);
		}
		if (g_first_candidate == NULL)
		{
			g_first_candidate = *table;
		}
		++i;
	}
	return (create_all_candidates(table, x + 1, len - 1, r));
}

t_table	*find_new_candidates_rec(t_table **table, char *line, int x, int *r)
{
	int		empty_len;
	t_table	*node;
	
	while (line[x] != 0 && line[x] == get_obstacle())
	{
		++x;
	}
	if (line[x] == 0)
		return (g_first_candidate);
	empty_len = 0;
	while (line[x] != 0 && line[x] == get_empty())
	{
		++empty_len;
		++x;
	}
	node = create_all_candidates(table, x - empty_len, empty_len, r);
	if (line[x] == 0)
		return (g_first_candidate);
	if (line[x] != get_empty() && line[x] != get_obstacle())
	{
		_log2("map error: unexpected char:",line+x);
		*r = 1;
		return (NULL);
	}
	return (find_new_candidates_rec(&node, line, x, r));
}

t_table	*find_new_candidates(char *line, int *r)
{
	t_table		*first;
	t_table		**pp_first;
	first = NULL;
	pp_first = &first;
	g_first_candidate = NULL;
	find_new_candidates_rec(pp_first, line, 0, r);
	return (g_first_candidate);
}


int		process_line(char *line, int line_number)
{
	int		r;
	t_table	*new_candidates;
	
	src_save_line(line);
	g_lines_read = line_number - 1;
	if (g_lines_read == -1)
	{
		r = parse_first_line(line);
		return (r);
	}
	if(validate_line(line, g_lines_read)!= 0)
		return (1);
	new_candidates = find_new_candidates(line, &r);
	if (r != 0)
	{
		_log("map error: wrong line\n");
		return (r);
	}
	remove_lt_len(&new_candidates, get_bsq().len);
	all_append_new_candidates(new_candidates);
	if (try_to_add_bsq(new_candidates))
	{
		all_remove_less_than_len(get_bsq().len);
	}
	return (0);
}
