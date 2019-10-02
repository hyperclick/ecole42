#include "libft.h"

char	*ft_str_remove_at(char *dst, const char src[], int n)
{
	return (ft_strcpy(dst + n, src + n + 1));
}
