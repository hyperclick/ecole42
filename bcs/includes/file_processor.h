#ifndef FILE_PROCESSOR
#include "bool.h"
#include "section.h"
#include "t_table.h"

int		process_buffer(char *rest, char *buffer, int buffer_length, int step);

void		print_to_out(int fd, char *str);

int		validate_line(char *line, int lines_read);

int			check_line(char *line);
int			get_lines_count();
char		get_obstacle();
char		get_empty();
char		get_full();

int			parse_first_line(char *line);
int			process_line(char *line, int line_number);

t_table		*all_get_table();
void		all_append_new_candidates(t_table *new_candidates);
void		all_table_clean();
void		all_remove_less_than_len(int len);
void		all_remove_conflicting_sections(t_table	*node);

t_section	get_bsq();
BOOL		is_better_than_bsq(t_section new_bsq);
BOOL		try_set_new_bsq(t_section new_bsq);
void		clear_bsq();
BOOL		try_to_add_bsq(t_table *new_candidates);


int		process_line_to_print_bsq(char *line, int line_number);

int		src_save_line(char *line);
int		src_recreate(void);
char	*src_get_file_name(void);

#endif
