#include "../libft/libft.h"
#include "tetramino.h"
#include "reader.h"

#ifndef TESTS

int main(int argc, const char * argv[])
{
	if (argc == 2)
	{
		solve(argv[1]);
	}
	ft_putchar('\n');
	return 0;
}
#endif
