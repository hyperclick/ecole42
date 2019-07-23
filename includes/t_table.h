#ifndef LIST_OF_SECTIONS_H
# define LIST_OF_SECTIONS_H

#include "section.h"

typedef struct	s_list_of_sections
{
	struct s_list_of_sections	*next;
	t_section					*data;
}				t_table;

t_table			*table_create(t_section *data);
#endif
