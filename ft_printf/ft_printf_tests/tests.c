#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "asserts.h"
#include "libstr.h"
	
int g_tests_count = 0;

void	test(const char *format, ...)
{
	char *e;
	char *a;
	int		e_r;
	int		a_r;
	int	size = 0;
	va_list argptr;


	printf("\ntest: %s\n", format);

	va_start(argptr, format);
	e_r = vprintf(format, argptr);
	va_end(argptr);

	/* Determine required size */

	va_start(argptr, format);
	size = vsnprintf(e, size, format, argptr);
	va_end(argptr);

	e = (char *)malloc(sizeof(char) * (size + 1));
	va_start(argptr, format);
	e_r = vsprintf(e, format, argptr);
	va_end(argptr);


	va_start(argptr, format);
	a = ft_vstprintf(&a_r, format, argptr);
	va_end(argptr);

	assert_str_equals(e, a);
	assert_int_equals(e_r, a_r);

	free(a);
	free(e);
	g_tests_count++;
}

void	test_number(const char *format)
{
	test(format, -1);
	test(format, 1);
	test(format, 0);
	test(format, INT_MAX);
	test(format, INT_MIN);
	test(format, -1.1);
	test(format, 1.0);
	test(format, 0.0);
	test(format, __LONG_LONG_MAX__);
	test(format, ULONG_MAX);
	test(format, LONG_MAX);
	test(format, LONG_MIN);
	test(format, LLONG_MIN);
	test(format, LLONG_MAX);
	test(format, ULLONG_MAX);
	//test(format, LONG_LONG_MIN);
	//test(format, ULONG_LONG_MAX);
		
}

void	test_char(const char *format)
{
	test(format, 'a');
	test(format, 300);
	test(format, 0);
	test(format, '\n');
}

void	test_format(char *format)
{
	test_number(format);
	test_char(format);

	free(format);
}

void	test_flags(char *flags)
{
	char	types[] = "udicoOxX";//psidaAeEfFgG
	char	t[] = " ";

	for (int i = 0; i < ft_strlen(types); i++)
	{
		t[0] = types[i];
		test_format(ft_strjoin2(3, "%", flags, t));
	}


	for (int w = -20; w < 50; w+=10)
	{
		char	*wd = ft_itoa(w);
		for (int i = 0; i < ft_strlen(types); i++)
		{
			t[0] = types[i];
			test_format(ft_strjoin2(3, "%", ft_strjoin(flags, wd), t));
		}

	}
	//free(flags);
}

int	main()
{
	test("%c  ...%.   ... %c",'a', 'b');
	test("%.-",'a');
	test("%0 3d",1);
	test("%#04x",1);
	test("%02d",1);
	test("%#-20d",-1);
	test("%1c",0);
	test("%2c",'a');
	test("%2c",0);
	test("%5d",1);
	test("%5d",-1);

	test("%1d",0);
	test("%1d",1);
	test("%1d",-1);
	test("1%");


	printf("%-+##++++++------      w\n");
	printf("%##++++++------      ww\n");
	printf("%  w\n");
	printf("%###O\n");
	printf("%####O\n");

	test("%#d", -1);



	//char *flags = "#+- 0";
	char *flags = "#+-0 ";
	char str[4];
	str[1] = 0;
	for (int i = 0; i < ft_strlen(flags); i++)
	{
		str[0] = flags[i];
		test_flags(str);
	}

	str[2] = 0;
	for (int i = 0; i < ft_strlen(flags); i++)
	{
		for (int j = 0; j < ft_strlen(flags); j++)
		{
			str[0] = flags[i];
			str[1] = flags[j];
			test_flags(str);
		}
	}

	str[3] = 0;
	for (int i = 0; i < ft_strlen(flags); i++)
	{
		for (int j = 0; j < ft_strlen(flags); j++)
		{
			for (int k = 0; k < ft_strlen(flags); k++)
			{
				str[0] = flags[i];
				str[1] = flags[j];
				str[2] = flags[k];
				test_flags(str);
			}
		}
	}
	
	test_flags(flags);
	
	//test_flags(strrev(flags));
	int q;

	test("%p", &q);
	test("%d", __LONG_LONG_MAX__);
	test("%u", __LONG_LONG_MAX__);
	test("%u", UINT_MAX);

	test("%y", 0);
	test("%O", 0);
	test("%#O", 0);
	test("%#O", 8);
	test("%#O", UINT_MAX);
	test("%#d", 0);
	test("%#d", -1);
	test("%#i", 0);
	test("%#i", -1);
	test("%#c", 'a');
	test("%#s", "abc");

	test("%", 0);

	test("%#X", 0);
	test("%#x", 16);
	test("%#x", UINT_MAX);

	test("%#X", 0);
	test("%#X", UINT_MAX);


	test("%#o", 0);
	test("%#o", UINT_MAX);

	test("%#O", 0);


	test("%x", -1);
	test("%x");
	test("%x", 0);
	test("%x", 1);
	test("%x", 9);
	test("%x", 10);
	test("%x", 15);
	test("%x", 16);
	test("%x", UINT_MAX);

	test("%X", 0);
	test("%X", UINT_MAX);


	test("%#d", INT_MAX);
	test("%#d", INT_MIN);
	test("%#d");


	test("%d", INT_MAX);
	test("%d", UINT_MAX);
	test("%d", INT_MIN);

	test("%d", INT_MAX);
	test("%d", UINT_MAX);
	test("%d", INT_MIN);
	test("%c%d");
	test("", 1, 'q');
	test("%s", "\0abc");
	test("%d");
	test("%c%c", 0, 0);
	test("%c", 0);
	test("%p");
	test("%s");
	test("%c");
	test("%p%c%d");
	test("%p%c%s%d");
	test("%d", 0);
	test("%%%%");
	test("111\n");
	test("%%1");
	test("%");
	test("%%%");
	test(NULL);
	test("%%");
	test("%%%%");
	test("111\n");
	test("1%d\n", 0);
	test("1%d1\n", 0);
	test("%s\n", "abc");
	test("'%s'\n", "abc");
	test("'%s'\n", "abc", 1);
	test("'%s' %d\n", "abc");
	test("%d", "abc");


	//test("%--");
	//test("%1");
	//test("%1", 0);
	//test("%%%1");
	//test("%%%%1");
	////test("---%*d----\n", 6, 5);
	//test("%#a", 0);
	//test("%#A", 0);
	//test("%#e", 0);
	//test("%#E", 0);
	//test("%#f", 0);
	//test("%#F", 0);
	//test("%#g", 0);
	//test("%#g", 0);

	//test("%a", UINT_MAX);

	printf("\n\n%d tests passed\n", g_tests_count);
}