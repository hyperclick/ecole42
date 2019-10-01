
#ifndef tetramino_h
#define tetramino_h

#include "../libft/libft.h"

typedef char	t_elem;

typedef struct s_tetramino
{
	t_elem	a[4][4];
}	t_t;

void	ft_lst_free_item(void *item, size_t size);
void	ft_lst_free(t_list **head);
void	*ft_lst_reduce(t_list *lst, void (*f)(t_list *elem, void *accumulator), void *accumulator);
int		ft_lst_count(t_list *lst);

#endif /* tetramino_h */
