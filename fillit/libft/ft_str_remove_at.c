#include "libft.h"

char	*ft_str_remove_at(char *dst, int n)
{
	return (ft_strcpy(dst + n, dst + n + 1));
}
