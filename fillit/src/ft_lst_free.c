#include "../libft/libft.h"

void ft_lst_free(t_list **head)
{
	if (*head != NULL)
	{
		ft_lstdel(head, ft_lst_free_item);
	}
}
