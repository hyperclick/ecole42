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
	if (o.sort_asc)
	{
		return (ft_strcmp(a, b));
	}

	if (o.sort_desc)
	{
		return (ft_strcmp(b, a));
	}

	if (o.mod_time_desc)
	{
		return (a.mod_time > b.mod_time)
		//return (fill_mod_time(a) > fill_mod_time(b));
	}

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