#ifndef FILE_PROCESSOR
#include "bool.h"
#include "section.h"

void		print_to_out(int fd, char *str);
void		process_files(int argc, char **argv);

int			check_line(char *line);
int			get_lines_count();
char		get_obstacle();
char		get_empty();
char		get_full();

int			parse_first_line(char *line);
int			process_line(char *line);


t_section	get_bsq();
BOOL		is_better_than_bsq(t_section new_bsq);
BOOL		try_set_new_bsq(t_section new_bsq);

#endif
