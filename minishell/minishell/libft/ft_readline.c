#include "libft.h"

void		ft_readline(char* dst, int size)
{
	char ch;
	while (read(1, &ch, 1) > 0)
	{
		if (--size == 0)
		{
			ft_putstr_fd("buffer is too small", STDERR_FILENO);
			exit(1);
		}
		ft_putchar(ch);
		if (ch == '\n')
		{
			break;
		}
		*dst++ = ch;
	}
	*dst = 0;
}