#include "../libft/libft.h"
#include "tetramino.h"
#include "reader.h"

#ifndef TESTS

int main2(int argc, const char * argv[])
{
	if (argc == 2)
	{
		t_list *list = read_file(argv[1]);
		ft_lst_free(&list);
	}
	ft_putchar('\n');
	return 0;
}
#endif
