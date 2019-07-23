#ifndef SECTION_H
# define SECTION_H

typedef struct	s_section
{
	int	y;
	int	x;
	int	len;
}				t_section;

char			*sec_to_string(char buffer[], t_section *section);
t_section		*create_heap_copy(t_section d);

#endif
