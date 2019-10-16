#include "libft.h"

int		ft_last_index(const char *str, const char to_find)
{
	size_t	len;

	len = ft_strlen(str);
	while (--len >= 0)
	{
		if (str[len] == to_find)
		{
			return (len);
		}
	}
	return (-1);
}
