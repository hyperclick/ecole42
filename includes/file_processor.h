#ifndef FILE_PROCESSOR

void	print_to_out(int fd, char *str);
void	process_files(int argc, char **argv);

int		check_line(char *line);
int		get_lines_count();
char	get_obstacle();
char	get_empty();
char	get_full();

int		parse_first_line(char *line);

#endif
