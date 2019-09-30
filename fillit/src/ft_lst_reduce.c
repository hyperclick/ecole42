#include "../libft/libft.h"

void	*ft_lst_reduce(t_list *lst, void (f)(t_list *elem, void *accumulator), void *accumulator)
{
	if (lst == NULL)
	{
		return (accumulator);
	}
	f(lst, accumulator);
	return (ft_lst_reduce(lst->next, f, accumulator));
}

