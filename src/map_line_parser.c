#include "../includes/ft.h"
#include "../includes/t_table.h"
#include "../includes/file_processor.h"
#include <stdio.h>


int		g_lines_read = -1;

t_table	*g_first_candidate = NULL;

t_table	*create_all_candidates(t_table *table, int x, int len, int *r)
{
	int	i;
	t_section data;
	
	if (len == 0)
	{
		return (table);
	}
	i = 1;
	while (i < len)
	{
		data.x = x;
		data.y = g_lines_read;
		data.len = i;
		table = table_append(table, data);
		if (table == NULL)
		{
			*r = -1;
			_log("failed to append data\n");
			return (NULL);
		}
		++i;
	}
	return(create_all_candidates(table, x + 1, len - 1, r));
}

t_table	*find_new_candidates_rec(t_table *table, char *line, int x, int *r)
{
	int		empty_len;
	t_table	*node;
	
	while (line[x] != 0 && line[x++] == get_obstacle())
	{
		
	}
	if (line[x] == 0)
	{
		return (g_first_candidate);
	}
	empty_len = 0;
	while (line[x] != 0 && line[x++] == get_empty())
	{
		++empty_len;
	}
	node = create_all_candidates(table, x, empty_len, r);
	if (line[x] == 0)
	{
		return (g_first_candidate);
	}
	if (line[x] != get_empty() && line[x] != get_obstacle())
	{
		*r = 1;
		return (NULL);
	}
	return (find_new_candidates_rec(node, line, x, r));
}

t_table	*find_new_candidates(char *line, int *r)
{
	g_first_candidate = NULL;
	return (find_new_candidates_rec(g_first_candidate, line, 0, r));
}
int		process_line(char *line)
{
	int		r;
	t_table	*new_candidates;
	
	++g_lines_read;
	if (g_lines_read == 0)
	{
		r = parse_first_line(line);
		return (r);
	}
	printf("'%s'\n", line);
	r = check_line(line);
	if (r != 0)
	{
		_log("lines lengths differ\n");
		printf("diff = %d, line = '%s'\n",r, line);
		return (r);
	}
	
	new_candidates = find_new_candidates(line, &r);
	if (r != 0)
	{
		//_log("wrong line\n");
		//printf("line = '%s'\n",r, line);
		return (r);
	}
	ft_putstr("new candidates:\n");
	//print_candidates(new_candidates);
	table_print_all(new_candidates);
	table_clean_all(new_candidates);
	
	//remove uncompatible candidates
	//try to add bsq (new_candidates)
	//print_map_with_bsq(bsq)
	//add_new_candidates(table, new_candidates);
	//print_map_with_candidates(table);
	
	return (0);
}
