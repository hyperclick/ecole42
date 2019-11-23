#include "libft.h"

void		ft_readline(char* dst, int size)
{
	char ch;
	while (read(1, &ch, 1) > 0)
	{
		if (--size == 0)
		{
			ft_e_putstr("buffer is too small");
			exit(1);
		}
		//char *clear = "0[[2K";
		//clear[0] = 27;
		ft_putchar(ch);
		//ft_putstr(clear);
		//printf("%c[2K", 27);
		ft_putstr("____");
		fflush(stdout);
		ft_putstr("\r ");
		printf("\33[2K\r");
		printf("\33[2K");
		if (ch == '\n')
		{
			break;
		}
		*dst++ = ch;
	}
	*dst = 0;
}