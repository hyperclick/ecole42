#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ft_str_is_alpha(char *str)
{
	if (*str > 'z' || *str < 'a' || *str > 'Z' || *str < 'A')
	{
		return 0;
	}
	return (ft_str_is_alpha(str + 1));
}
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*str != 0)
	{
		ft_putchar(*str++);
	}
	ft_putchar('\n');
}


int		is_digit(char c)
{
	return (c > '0' && c <= '9') ? 1 : 0;
}

int		is_number(char *str)
{
	while (*str != 0)
	{
		if (is_digit(*str) == 0)
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int		ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i++] != 0)
	{
	}
	return (i - 1);
}



char	*uitoa(int n, char *r)
{
	if (n < 10)
	{
		*r = (char)('0' + n);
		r++;
		return (r);
	}
	return (uitoa(n % 10, uitoa(n / 10, r)));
}

char	*itoa(int n, char *r)
{
	char *str;
	
	str = r;
	if (n < 0)
	{
		*r = '-';
		r++;
		n = -n;
	}
	r = uitoa(n, r);
	*r = '\0';
	return (str);
}


void	ft_putnbr(int nb)
{
	const	int	max_int_length = 12;
	char		r[max_int_length];
	
	ft_putstr(itoa(nb, r));
}

char *ft_strupcase(char *str);
/*
void test(char *s1, char *s2, unsigned int n)
{
	printf("'%s'\t'%s':\t'%d'\t'%d'\n", s1, s2, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
}*/
void test(char *s1)
{
	//printf("'%s'\t'%s'\n", s1, ft_strupcase(s1));
	printf("'%s'", s1);
	printf("'%s'\n", ft_strupcase(s1));
	//ft_strupcase(s1);
}


int	main(void)
{
	char st[] = "aQaQ";
	test(st);
	
	char s2[] = "AqAq";
	test(s2);
	
	char s1[] = "aq";
	test(s1);
	
	char s[] = "z";
	
	test(s);
	
	test("");
	
	
	char s3[] ="Assd fdsgf";
	test(s3);
	/*
	test("ret", "ret");
	
	test("1", "0");
	test("10", "00");
	test("11", "00");
	test("10", "0");
	test("11111111", "0");
	test("A","a");
	test("", "1");
	test("", "0");
	//test(0, "");
	test("\0", "1");
	test("1", "");
	test("1", "\0");
	test("qqq", "q");
	test("5678", "67");
	test("1234567890", "6789");
	
	test("qwreret", "ret");
	test("reret", "ret");
	test("rret", "ret");
	test("1", "11");
	*/
	return (0);
}
