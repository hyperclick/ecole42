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

char	*ft_strcpy(char *dest, char *src);

void test(char *dest, char *src, int n)
{
	printf("strncpy:\t'%s'\n", strcpy(dest, src));
	printf("ft_strncpy:\t'%s'\n", ft_strcpy(dest, src));
}


int	main(void)
{
	char d0[0];
	char d1[1];
	char d2[2];
	char d3[3];
	
	printf("ft_strncpy:\t'%s'\n", ft_strcpy(d2, "123"));
	//printf("strncpy:\t'%s'\n", strcpy(d2, "12"));
	printf("strncpy:\t'%s'\n", strcpy(d2, "1"));
	printf("ft_strncpy:\t'%s'\n", ft_strcpy(d2, "1"));
	printf("strncpy:\t'%s'\n", strcpy(d1, ""));
	printf("ft_strncpy:\t'%s'\n", ft_strcpy(d1, ""));
	printf("strncpy:\t'%s'\n", strcpy(d1, "\0"));
	printf("ft_strncpy:\t'%s'\n", ft_strcpy(d1, "\0"));
	printf("strncpy:\t'%s'\n", strcpy(d3, "12"));
	printf("ft_strncpy:\t'%s'\n", ft_strcpy(d3, "12"));
	printf("strncpy:\t'%s'\n", strcpy(d1, ""));
	printf("ft_strncpy:\t'%s'\n", ft_strcpy(d1, ""));
	printf("strncpy:\t'%s'\n", strcpy(d1, ""));
	printf("ft_strncpy:\t'%s'\n", ft_strcpy(d1, ""));
	/*	*/
	return(0);
	//strcpy("qqq","1");
	//test("qqq","1");
	//test("","");
	//("","\0");
	
	return(0);
	ft_putchar('\n');
	
	//int q =	ft_recursive_power(2,10);
	//print_num(q);
	ft_putchar('\n');
	//ft_putchar('\n');
	//ft_putchar((char)(q+'0'));
	return (0);
}
