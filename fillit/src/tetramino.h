
#ifndef tetramino_h
#define tetramino_h

#include "../libft/libft.h"

typedef char	t_elem;
static const	t_elem	EMPTY_ELEM2 = '.';

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

extern t_t		g_figures[26];
extern int		g_figures_count;

BOOL	is_empty(t_elem e);

t_t		get_figure(char letter);
char	*make_rest(char *rest);

void	print_figures(void);
void	print_r(t_r r);


t_r		append_path(t_r r, t_elem letter);
t_r		append(t_r r, int row, int col, t_t	t);
t_r		create_r(int width);
t_r		r_fill_all(t_r r, t_elem value);

void	solve(const char *file_name);

#endif /* tetramino_h */
