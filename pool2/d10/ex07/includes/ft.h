#ifndef FT_H
# define FT_H
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "bool.h"

char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
int		is_digit(char c);
int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int	ft_putchar(char c);
void	ft_putstr(char *str);


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

int		count_words(char *str)
{
	int len = 0;
	if (*str == 0)
	{
		return 0;
	}
	BOOL previous_is_space = TRUE;
	while (*str != 0)
	{
		//printf("*str = '%c', len = %d\n", *str, len);
		while (*str == ' ')
		{
			++str;
			previous_is_space  = TRUE;
		}
		if (*str == 0)
		{
			return len;
		}
		if (*str != ' ')
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


char**	split(char *str, int *len)
{
	*len = count_words(str);
	char	**r = malloc(sizeof(char*) * *len);
	if (*str==0)
	{
		return r;
	}
	int j = 0;
	BOOL previous_is_space = TRUE;
	char*tmp;
	printf("len = %d\n", *len);
	while (*str != 0)
	{
		//printf("*str = '%s'\n", str);
		while (*str == ' ')
		{
			++str;
			previous_is_space  = TRUE;
		}
		if (*str != ' ')
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
	return r;
}



void print_string_array(char **a)
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













#endif
