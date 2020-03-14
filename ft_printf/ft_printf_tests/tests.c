#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "asserts.h"
#include "libstr.h"

int g_tests_count = 0;
int g_failed_tests_count = 0;

void	test2(BOOL mac_only, const char* format, va_list argptr)
{
	char* e;
	char* a;
	int		e_r;
	int		a_r;
	int	size = 0;
	va_list arg0;
	va_list arg1;
	va_list arg2;
	va_list arg3;
	//va_list arg4;
	//va_copy(arg4, argptr);
	g_tests_count++;
	if (g_tests_count < 0)
	{
		return;
		//exit(1);
	}
	if (g_failed_tests_count > 10000)
	{
		//return;
		exit(1);
	}
	printf("test #%d: '%s': '", g_tests_count, format);

	va_copy(arg0, argptr);
	//va_start(argptr, format);
	e_r = vprintf(format, arg0);
	va_end(arg0);
	printf("'\n");

	/* Determine required size */

	//va_start(argptr, format);
	va_copy(arg1, argptr);
	size = vsnprintf(e, size, format, arg1);
	va_end(arg1);

	e = (char*)malloc(sizeof(char) * (size + 1));
	//va_start(argptr, format);
	va_copy(arg2, argptr);
	e_r = vsprintf(e, format, arg2);
	va_end(arg2);

	va_copy(arg3, argptr);
	//va_start(argptr, format);
	a = ft_vstprintf(&a_r, format, arg3);
	va_end(arg3);


#ifdef MAC_OS
	mac_only = FALSE;
#else 
#endif // MAC_OS
	if (!mac_only)
	{
		//assert_str_equals(e, a);
		//assert_int_equals(e_r, a_r);

		if (!ft_strequ(e, a))
		{
			g_failed_tests_count++;
			printf("assert failed: expected: '%s', actual: '%s'\n", e, a);
			dprintf(STDERR_FILENO, "test %d '%s' failed: expected: '%s', actual: '%s'\n", g_tests_count, format, e, a);
			//exit(1);
		}
		if (e_r!=a_r)
		{
			printf("assert failed: expected: '%d', actual: '%d'\n", e_r, a_r);
			dprintf(STDERR_FILENO, "test %d '%s' failed: expected: '%d', actual: '%d'\n", g_tests_count, format, e_r, a_r);
			//exit(1);
		}
	}
	else
	{
		printf("ignored\n");
	}

	free(a);
	free(e);
}

void	test(const char* format, ...)
{
	va_list argptr;
	va_start(argptr, format);
	test2(FALSE, format, argptr);
	va_end(argptr);
}

void	test_mac(const char* format, ...)
{
	va_list argptr;
	va_start(argptr, format);
	test2(TRUE, format, argptr);
	va_end(argptr);
}

void	test_number(const char* format)
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
	char* str = ft_strjoin2(3, "|%d|", format, "|%c|");
	test(str, 1, 2, 'a');
	free(str);
}

void	test_char(const char* format)
{
	test(format, 'a');
	test(format, 300);
	test(format, 0);
	test(format, '\n');
	char* str = ft_strjoin2(3, "|%d|", format, "|%d|");
	test(str, 99999999, 'a', 1);
	free(str);
}
void	test_pointer(char* format)
{
	long q = INT_MAX;
	test(format, q);
	test(format, &q);
	char* str = ft_strjoin2(3, "|%d|", format, "|%s|");
	test(str, 99999999, &q, "abc");
	free(str);
}

void	test_string(char* format)
{
	test(format, "");
	test(format, NULL);
	test(format, "a");
	test(format, "abc");
	char* q = "qwe";
	test(format, q);

	char* str = ft_strjoin2(3, "|%d|", format, "|%s|");
	test(str, 99999999, q, "abc");
	free(str);
}

void	test_format(char* format)
{
	char	types[] = "diuoxXcpsaAeEfFgG";//DOU
	char* tmp;
	char	type[] = " ";
	char* initial_format = format;

	for (int i = 0; i < ft_strlen(types) + 1; i++)
	{
		tmp = initial_format;
		type[0] = types[i];
		format = ft_strjoin(tmp, type);
		if (ft_contains("diuoxXc", types[i]) || types[i] == 0)
		{
			test_number(format);
			test_char(format);
		}
		if (types[i] == 'p' || types[i] == 's' || types[i] == 0)
		{
			if (types[i] != 's')
			{
				test_pointer(format);
			}
			test_string(format);
		}
		free(format);
	}
		free(initial_format);
}

void	test_width(char* flags, char* p, char* w)
{
	char* l[] = { "", "h", "hh", "l", "ll", "L", "j", "z", "t" };

	for (int i = 0; i < 9; i++)
	{
		test_format(ft_strjoin2(5, "%", flags, w,  p, l[i]));
	}
}

void	test_precision(char* flags, char* p)
{
	char* w[] = { "", "-10", "-5", "0", "5", "10" };

	for (int i = 0; i < 6; i++)
	{
		test_width(flags, p, w[i]);
	}
}

void	test_flags(char* flags)
{
	char* p[] = { "", ".-10", ".-5", ".0", ".5", ".10" };
	//char* p[] = { "", ".2", ".1", ".0", ".5", ".10" };

	test_format(ft_strjoin2(2, "%", flags));

	for (int i = 0; i < 6; i++)
		test_precision(flags, p[i]);
}

