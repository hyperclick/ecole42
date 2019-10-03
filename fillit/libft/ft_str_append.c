#include "libft.h"

void	ft_str_append(char	*str, const char letter)
{
	size_t	len;
	len = ft_strlen(str);
	str[len] = letter;
	str[len + 1] = 0;
}
