#ifndef FT_H
# define FT_H
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "bool.h"

const int	LAST_INT = -3333333;

char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
int		is_digit(char c);
int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_putchar(char c);
void	ft_putstr(char *str);
int		atoi(char* str);
BOOL	is_digit(char c);
BOOL	try_parse(char* str, int *n);

int ft_str_is_alpha(char *str)
{
	if (*str > 'z' || *str < 'a' || *str > 'Z' || *str < 'A')
	{
		return 0;
	}
	return (ft_str_is_alpha(str + 1));
}

void new_line()
{
	ft_putchar('\n');
}

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int		i;
	
	if (tab == NULL || f == NULL)
	{
		ft_putstr("tab == NULL || f == NULL");
		return ;
	}
	i = 0;
	while (i < length)
	{
		f(tab[i++]);
	}
}

void	print_params(int argc, char **argv, int i)
{
	if (argc == 0)
	{
		return ;
	}
	ft_putstr(argv[i]);
	ft_putchar('\n');
	print_params(argc - 1, argv, i + 1);
}

BOOL	contains(char *delimeters, char c)
{
	//printf("search '%c' in '%s'\n", c, delimeters);
	while (*delimeters != 0)
	{
		//printf("cmp '%c' with '%c'\n", c, *delimeters);
		if (c == *delimeters)
		{
			//printf("string '%s' contains '%c'\n", delimeters, c);
			return (TRUE);
		}
		++delimeters;
	}
	return (FALSE);
}


int		count_words(char *str, char *delimeters)
{
	int len = 0;
	if (*str == 0)
	{
		return 0;
	}
	BOOL previous_is_space = TRUE;
	while (*str != 0)
	{
		//printf("1*str = '%c', len = %d, delimeters = '%s'\n", *str, len, delimeters);
		while (contains(delimeters, *str))
		{
			++str;
			//printf("2*str = '%c', len = %d\n", *str, len);
			previous_is_space  = TRUE;
		}
		if (*str == 0)
		{
			return len;
		}
		if (!contains(delimeters, *str))
		{
			if (previous_is_space == TRUE)
			{
				++len;
			}
			previous_is_space = FALSE;
			++str;
		}
	}
	return len;
}


char**	split(char *str, int *len, char *delimeters)
{
	*len = count_words(str, delimeters);
	char	**r = malloc(sizeof(char*) * (*len + 1));
	if (*str==0)
	{
		return r;
	}
	int j = 0;
	BOOL previous_is_space = TRUE;
	char*tmp;
	//printf("this len = %d\n", *len);
	while (*str != 0)
	{
		//printf("*str = '%s'\n", str);
		while (contains(delimeters, *str))
		{
			++str;
			previous_is_space  = TRUE;
		}
		if (!contains(delimeters, *str))
		{
			if (previous_is_space == TRUE)
			{
				if (j > 1)
				{
					//printf("r[%d] = '%s'", j - 1, r[j - 1]);
				}
				r[j] = malloc(sizeof(char) * ft_strlen(str));
				tmp = r[j++];
			}
			previous_is_space = FALSE;
			//printf("j:%d\n", j);
			*tmp = *str;
			++tmp;
			++str;
		}
	}
	r[*len] = 0;
	return r;
}

void print_string_array(char *a[])
{
	if (a == NULL)
	{
		ft_putstr("(NULL)\n");
		return;
	}
	while (*a != 0)
	{
		printf("\"%s\"\n", *a);
		++a;
	}
	//printf("---end---");
	
}
char **make_string_array(char *dst[], char *str, ...)
{
	va_list arg;
	//char *s = str;
	long diff = 2;
	va_start(arg, str);
	int i = 0;
	while (str && diff == 2) {
		printf("begin: i = %d\n", i);
		dst[i] = str;
		printf("\tstr = '%s', dst[%d] = '%s'\n", str,i, dst[i]);
		//s = str + sizeof(char *);
		str = va_arg(arg, char*);
		diff = str - dst[i];
		printf("end: i = %d: diff = %ld\n", i, diff);
		++i;
		//printf("%p", str);
		//printf("str = '%s'", str);
		printf("\n");
	}
	
	va_end(arg);
	dst[i] = 0;
	//printf("array:\n");
	//print_string_array(dst);
	return dst;
}

int*	convert_to_int_array(int dst[], char	*a[])
{
	int i=0;
	while (a[i] != 0)
	{
		//printf("a[%d] = '%s'\n", i, a[i]);
		dst[i] = atoi(a[i]);
		//printf("dst[%d] = %d\n", i, dst[i]);
		++i;
	}
	dst[i] = LAST_INT;
	//printf("exit %s\n", __func__);
	return (dst);
}

void	print_int_array(int a[])
{
	int i = 0;
	while (a[i] != LAST_INT)
	{
		printf("%d ", a[i]);
		++i;
	}
	printf("\n");
}









#endif
