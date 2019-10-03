
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

static t_t		g_figures[26];
static int		g_figures_count;

BOOL	is_empty(t_elem e);

#endif /* tetramino_h */
