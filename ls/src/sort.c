#include "ls.h"

void	swap(t_entry entries[], int i, int j)
{
	t_entry	tmp;

	tmp = entries[i];
	entries[i] = entries[j];
	entries[j] = tmp;
}

BOOL	need_swap(t_entry a, t_entry b, t_sort_options o)
{
	BOOL	second_is_greter;
	if (o.sort_by == SORT_BY_MOD_TIME)
	{
		second_is_greter = b.s.st_mtime >= a.s.st_mtime;
	//	if (b.mod_time == a.mod_time)
	//	{
	//		second_is_greter =
	//	}
	}
	if (o.sort_by == SORT_BY_NAME)
	{
		second_is_greter = (ft_strcmp(b.full_name.name, a.full_name.name) >= 0);
	}
	BOOL	need_to_swap = o.sort_desc == TRUE ? second_is_greter : !second_is_greter;
	return (need_to_swap);

	printf("undefined sort");
	exit(2);
}

t_entry* sort(t_entry entries[], int count, t_sort_options o)
{
	int	i;
	BOOL	not_sorted;
	
	not_sorted = TRUE;
	while (not_sorted)
	{
		not_sorted = FALSE;
		i = -1;
		while (++i < count - 1)
		{
			if (need_swap(entries[i], entries[i + 1], o))
			{
				swap(entries, i, i + 1);
				not_sorted = TRUE;
			}
		}
	}
	return (entries);
}