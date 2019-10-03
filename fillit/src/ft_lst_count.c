#include "../libft/libft.h"

void	ft_count(t_list *elem, void *accumulator)
{
	int *p_count;

	if (elem == NULL)
	{
		return ;
	}
	p_count = (int*)accumulator;
	(*p_count)++;
}

int		ft_lst_count(t_list *lst)
{
	int	count;
	count = 0;
	ft_lst_reduce(lst, ft_count, &count);
	
	return (count);
}

