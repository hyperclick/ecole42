#include "../libft/libft.h"

void	ft_lst_free_item(void *item, size_t size)
{
	if (size == 0)
	{
		exit(1);
	}
	free(item);
}
