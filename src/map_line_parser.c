#include "../includes/ft.h"
#include "../includes/t_table.h"
#include "../includes/file_processor.h"
#include <stdio.h>


int		g_lines_read;
//int		g_lines_len;

t_table	*g_first_candidate = NULL;

t_table	*create_all_candidates(t_table **table, int x, int len, int *r)
{
	//printf("x = %d, len = %d\n", x, len);
	int	i;
	t_section data;
	t_table		*node;
	
	if (len == 0)
	{
		return (*table);
	}
	i = get_bsq().len + 1;
	while (i <= len)
	{
		data.x = x;
		data.y = g_lines_read;
		data.len = i;
		node = table_append(table, data);
		if (node == NULL)
		{
			*r = -1;
			_log("failed to append data\n");
			return (NULL);
		}
		++i;
	}
	return(create_all_candidates(&node, x + 1, len - 1, r));
}

t_table	*find_new_candidates_rec(t_table **table, char *line, int x, int *r)
{
	int		empty_len;
	t_table	*node;
	//printf("line[%d] = '%c'\n",x, line[x]);
	while (line[x] != 0 && line[x] == get_obstacle())
	{
		++x;
	}
	if (line[x] == 0)
	{
		return (g_first_candidate);
	}
	//git printf("line[%d] = '%c'\n",x, line[x]);
	empty_len = 0;
	while (line[x] != 0 && line[x] == get_empty())
	{
		++empty_len;
		++x;
	}
	//++empty_len;
	node = create_all_candidates(table, x - empty_len, empty_len, r);
	if (line[x] == 0)
	{
		return (g_first_candidate);
	}
	if (line[x] != get_empty() && line[x] != get_obstacle())
	{
		printf("map error: unexpected char:\t'%c', empty = '%c'\n", line[x], get_empty());
		_log("map error: unexpected char:");
		_log(line+x);
		*r = 1;
		return (NULL);
	}
	return (find_new_candidates_rec(&node, line, x, r));
}

t_table	*find_new_candidates(char *line, int *r)
{
	g_first_candidate = NULL;
	return (find_new_candidates_rec(&g_first_candidate, line, 0, r));
}

void	print_table(char *caption, t_table *table)
{
	ft_putstr(caption);
	new_line();
	table_print_header();
	table_print_all(table);
	new_line();
}

int		process_line(char *line, int line_number)
{
	static int	lines_len;
	int		r;
	t_table	*new_candidates;
	t_table	*all;
	
	g_lines_read = line_number - 1;
	printf("line %d: '%s'\n", g_lines_read, line);
	if (g_lines_read == -1)
	{
		r = parse_first_line(line);
		return (r);
	}
	if (g_lines_read == 0)
	{
		lines_len = ft_strlen(line);
	}
	else
	{
		r = (lines_len - ft_strlen(line));
		if (r != 0)
		{
			_log("lines lengths differ\n");
			printf("diff = %d, line = '%s'\n",r, line);
			return (r);
		}
	}
	
	new_candidates = find_new_candidates(line, &r);
	if (r != 0)
	{
		_log("map error: wrong line\n");
		//printf("line = '%s'\n",r, line);
		return (r);
	}
	//table_clean_all(new_candidates);
	
	//try add first candidate
	all = all_get_table();
	if (all == NULL)
	{
		if (new_candidates != NULL)
		{
			try_set_new_bsq(*new_candidates->data);
		}
	}
	print_table("before remove candidates", new_candidates);
	remove_less_than_len(&new_candidates, get_bsq().len);
	print_table("after remove candidates", new_candidates);
	remove_less_than_len(&all, get_bsq().len);
	//remove_conflicting_sections(new_candidates);
	printf("m_get_count = %d\n", m_get_count() );
	all_append_new_candidates(new_candidates);
	print_table("\n\n----entire table:\n", all_get_table());
	BOOL b = try_to_add_bsq(new_candidates);
	t_section bsq = get_bsq();
	printf("bsq found = %d: {%d:%d,%d}\n", b, bsq.x, bsq.y, bsq.len);
	//print_map_with_bsq(bsq)
	//print_map_with_candidates(table);
	
	
	return (0);
}
