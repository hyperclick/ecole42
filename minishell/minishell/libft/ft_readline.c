#include "libft.h"

void		ft_readline(char* dst, int size)
{
	char ch;
	while (read(STDIN_FILENO, &ch, 1) > 0)
	{
		if (--size == 0)
		{
			ft_e_putstr("buffer is too small");
			exit(1);
		}
		if (ch == '\n')
		{
			break;
		}
		*dst++ = ch;
	}
	*dst = 0;
}