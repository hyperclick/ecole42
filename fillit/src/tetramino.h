#ifndef tetramino_h
#define tetramino_h

#include "../libft/libft.h"

typedef char	t_elem;
static const	t_elem	EMPTY_ELEM = '.';
static const	t_elem	FILLED_ELEM = '#';

typedef struct s_tetramino
{
	t_elem	a[4][4];
	char	letter;
}	t_t;

typedef struct	s_result
{
	int		height;
	int		width;
	t_elem	a[11][11];
	char	path[255];
	BOOL	found;
	int		deep;
}				t_r;

BOOL	is_neighbour_empty(t_t t, int row, int col);
BOOL	is_input_filled(t_elem e);
BOOL	validate_figure(t_t t);
t_t		normalize(t_t f);
BOOL	read_file(const char	*filename);

t_t		get_figure(char letter);
int		get_figures_count(void);
void	set_figures_count(int count);
void	add_figure(t_t t);
char	*make_rest(char *rest);

void	print_figure(t_t f);
void	print_figures(void);
void	print_r(t_r r);


t_r		append_path(t_r r, t_elem letter);
t_r		append(t_r r, int row, int col, t_t	t);
t_r		create_r(int width);
t_r		r_fill_all(t_r r, t_elem value);

void	solve(const char *file_name);

#endif /* tetramino_h */
