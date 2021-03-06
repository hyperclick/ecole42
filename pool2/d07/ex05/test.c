#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
char	*ft_strcpy(char *dest, char *src)
{
	int len;
	
	len = 0;
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
		len++;
	}
	return (dest - len);
}
 */
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
void	ft_putstr(char *str);
/*
void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*str != 0)
	{
		ft_putchar(*str++);
	}
	//ft_putchar('\n');
}

*/
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
/*
int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i++] != 0)
	{
	}
	return (i - 1);
}
*/


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

void new_line()
{
	ft_putchar('\n');
}
void	ft_putnbr(int nb)
{
	const	int	max_int_length = 12;
	char		r[max_int_length];
	
	ft_putstr(itoa(nb, r));
}

void	print_word(char* r[], int n)
{
	ft_putstr("w");
	ft_putnbr(n);
	ft_putstr(":\t'");
	ft_putstr(r[n]);
	ft_putstr("'\n");
	
}
void	print_char(char *name, char c)
{
	ft_putstr(name);
	ft_putstr(":\t'");
	ft_putchar(c);
	ft_putstr("'\n");
}
void	print_num(char *str, int n)
{
	ft_putstr(str);
	ft_putstr(":\t");
	ft_putnbr(n);
	ft_putstr("\n");
	
}
void	print_array(int a[], int i, int n)
{
	//ft_putstr("n");
	//ft_putnbr(n);
	if (--n < 0)
	{
		return;
	}
	//ft_putstr("n");
	//ft_putnbr(n);
	if (a == NULL)
	{
		ft_putstr("(NULL)");
		return;
	}
	//ft_putstr("a");
	ft_putnbr(a[i]);
	if (n!= 0)
	{
		ft_putstr(", ");
	}
	print_array(a, i + 1, n);
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

int get_len(char *a[])
{
	int i = 0;
	//while (ft_strlen(a[i]) != 0)
	while (*a[i] != 0)
	{
		i++;
	}
	return i;
}

void print_string_array(char *a[])
{
	int i = 0;
	//while (ft_strlen(a[i]) != 0)
	while (*a[i] != 0)
	{
		ft_putchar('\'');
		ft_putstr(a[i]);
		ft_putstr("'\n");
		i++;
	}
	
}
void ft_print_words_tables(char **tab);
char **ft_split_whitespaces(char *str);
/*
void test(char *s1, char *s2, unsigned int n)
{
	printf("'%s'\t'%s':\t'%d'\t'%d'\n", s1, s2, strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
}*/
void test(char *str)
{
	ft_putstr("initial string:\t'");
	ft_putstr(str);
	ft_putstr("'\n");
	//printf("'%s'\t'%s'\n", s1, ft_strupcase(s1));
	char	**a = NULL;//*a[] = NULL;
	//a = malloc(1);
	//ft_putstr(str);
	//ft_putstr(":\n");
	//printf("%s ->\n", min, max, ft_ultimate_range(&a, min, max));
	a = ft_split_whitespaces(str);
	
	if (a == NULL)
	{
		ft_putstr("(NULL)\n");
		return;
	}
	if (*a == NULL)
	{
		ft_putstr("(NULL)\n");
		return;
	}
	ft_print_words_tables(a);
	//print_string_array(a);
	//print_params(get_len(a), a, 0);
	//new_line();
	free (a);
	//printf("'%s'\n", ft_strupcase(s1));
	//ft_strupcase(s1);
}


int	main()
{
	test("    qqqq \t \nq      qqqq      ww      ");
	//return 1;
	test("");
	//return 1;
	test("q ");
	//return 1;
	test(" q");
	//return 1;
	test("a b");
	test("    q \t \nq      q      w      ");
	//return 1;
	test("\0");
	test(" ");
	test("\t");
	test("\n");
	test(" \t\n");
	test("     ");
	test(" q");
	test(" q ");
	test(" a b q q ");
	test("q \t \n");
	test("q \t \nq");
	test("\t \nq");
	test("\n   \tq \t \n");
	//ft_putstr("\n");
	/*
	test(0,1);
	test(0,2);
		test(1,0);
	test(0,0);
	
	test(-1,0);
	//
	test(0,10);
	test(-2,-1);
	test(-10,-0);*/
	/*
	char st[] = "aQaQ";
	test(st);
	
	char s2[] = "AqAq";
	test(s2);
	
	char s1[] = "aq";
	test(s1);
	
	
	test(s);
	
	test("");
	
	
	char s3[] ="Assd fdsgf";
	test(s3);*/
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
