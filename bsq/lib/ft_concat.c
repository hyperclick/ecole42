#include "../includes/ft.h"

char	*ft_concat(char *dst, char *a, char *b)
{
	ft_strcpy(dst, a);
	ft_strcpy(dst + ft_strlen(a), b);
	
	return (dst);
}

char	*ft_concat3(char *dst, char *a, char *b, char *c)
{
	ft_concat(dst, a, b);
	ft_concat(dst, dst + ft_strlen(a) + ft_strlen(b), c);
	
	return (dst);
}
