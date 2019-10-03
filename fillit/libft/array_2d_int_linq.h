#include "libft.h"

typedef struct s_array_2d_int
{
	int		height;
	int		width;
	int		**a;
}				t_a2_int;

t_a2_int	a2_map(t_a2_int a, int (*f)(int e, int i, int j));
//BOOL	a2_any(t_a2, BOOL (*f)(void *e, int i, int j));
