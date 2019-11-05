#include "libft.h"

BOOL		ft_ends_with(const char *str, const char c)
{
	return (str[ft_strlen(str) - 1] == c);
}
