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

char *ft_strstr(char *str, char *to_find);

void test(char *str, char *to_find)
{
	printf("strstr:\t\t'%s'\n", strstr(str, to_find));
	
	printf("ft_strstr:\t'%s'\n", ft_strstr(str, to_find));
}


int	main(void)
{
	
	test("", "1");
	test("\0", "1");
	test("1", "");
	test("1", "\0");
	test("qqq", "q");
	test("qwreret", "ret");
	
	test("1", "11");
	test("123456789", "6789");
	
	
	return (0);
}
