#include "ls.h"

int     get_columns_count(t_print_options o)
{
    return (1);
}
int     get_rows_count(int entries_count, int cols_count)
{
    return (entries_count/cols_count);
}
void    print(t_entry e, t_print_options o)
{
    t_entry q = e;
   printf("%s ", e.full_name.name);
}

void		print_entries(t_entry	entries[MAX_FSO_IN_DIR], int count, t_print_options o)
{
	int	cols_count = get_columns_count(o);
	int	rows_count = get_rows_count(count, cols_count);
	for (int i = 0; i < rows_count; i++)
	{
		for (int j = 0; j < cols_count; j++)
		{
			print(entries[i * cols_count + j], o);
		}
		printf("\n");
	}
}