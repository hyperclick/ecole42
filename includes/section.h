#ifndef SECTION_H
# define SECTION_H

typedef struct	s_section
{
	int	y;
	int	x;
	int	len;
}				t_section;


char			*sec_to_table_entry(char buffer[], t_section *section);


#endif
