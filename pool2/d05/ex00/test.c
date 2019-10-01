#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
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



void	ft_putstr(char *str);



int	main(void)
{
	ft_putstr("");
	test("1");
	test("11");
	test("a");
	
	test("A");
	
	test("aQaQ");
	test("AqAq");
	
	test(" ");
	test("Assd fdsgf");
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
