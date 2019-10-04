#ifndef tetramino_linq_h
#define tetramino_linq_h

#include "../libft/libft.h"
#include "tetramino.h"

BOOL	all_empty(t_t t);
BOOL	t_any(t_t	t, int (*f)(char e));
#endif /* tetramino_linq_h */
