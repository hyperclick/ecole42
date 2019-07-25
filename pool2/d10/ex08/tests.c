#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "includes/ft.h"





char	*substring(char *str, char separator)
{
	int len = 0;
	while (str[len] && str[len]!=separator)
	{
		++len;
	}
	
	char	*dst = malloc(sizeof(char*) * (len + 1));
	ft_strncpy(dst, str, len);
	
	dst[len + 1] = 0;
	return dst;
}

char **_a(char *dst[], char *str)
{
	//printf("enter %s: str = '%s'\n", __func__, str);
	int i = 0; 
	
	while (*str != 0 && i < 100)
	{
		//printf("str = '%s'\n", str);
		dst[i] = substring(str, ',');
		//printf("dst[%d] = '%s'\n", i, dst[i]);
		str += ft_strlen(dst[i]);
		if(*str==',')
			{
				++str;
			}
		//printf("i=%d, str = '%s', *str = %d, *str == 0: %d\n", i, str, *str, *str == 0);
		++i;
	}
	//dst[i] = "qqqqq";
	dst[i] = 0;
	//printf("exit %s: i = %d\n", __func__, i);
	return dst;
}

void ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *));
/*
 void test(char *s1, char *s2, unsigned int n)
 {
 printf("'%s'\t'%s':\t'%d'\t'%d'\n", s1, s2, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
 }*/
void test(char *a[])
{
	printf("\n************\narray:\n");
	print_string_array(a);
	//print_array(a, len, 0);
	//printf("\nis sorted: %d:%d\n",expected, ft_is_sort(a, len, &cmp));
	ft_advanced_sort_wordtab(a, &ft_strcmp);
	
	printf("\nsorted array:\n");
	print_string_array(a);
	printf("\n************\n");
	
}

int	main()
{setvbuf (stdout, NULL, _IONBF, 0);
	ft_putstr("\n\n\n----------------------------\n\n\n");
	char *a[10];
	test(_a(a, "1,2,3"));
	test(_a(a, "3,2,1ss1"));
	//test(_a(a, "1,ss2,ss3"));
	return 1;
	return (0);
}

