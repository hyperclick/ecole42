#ifndef LIST_OF_SECTIONS_H
# define LIST_OF_SECTIONS_H

#include "section.h"

typedef struct	s_list_of_sections
{
	struct s_list_of_sections	*next;
	t_section					*data;
}				t_table;

t_table			*table_create(t_section *data);
void			table_clean_all(t_table **node);
void			table_print_header();
void			table_print_all(t_table *node);
t_table			*table_append(t_table **node, t_section data);
t_table			*get_last_node(t_table *table);
void			table_append_node(t_table *table, t_table *new_nodes);
t_section		try_make_square(t_table *node);
void			remove_lt_len(t_table	**pp_table, int len);

#endif
