#include "libft.h"

void	ft_str_remove_at(char *dst, int n)
{
	(ft_strcpy(dst + n, dst + n + 1));
}
/*
char	*ft_str_dup_remove_at(const char str[], int n)
{
	return (ft_str_remove_at(ft_strdup(str), src, n));
}

void	ft_str_remove_at_self(char str[], int n)
{
	ft_str_remove_at(str, str, n);
}
*/
