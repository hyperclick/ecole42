#include "../includes/ft.h"
#include <unistd.h>

void	print_to_out(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}
