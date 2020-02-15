#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "asserts.h"
#include "libstr.h"

int g_tests_count = 0;

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
	//if (!ft_str_contains(format, "lc"))
	{
		test(format, INT_MIN);
	}
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
	char* str = ft_strjoin2(3, "_%d_", format, "_%c_");
	test(str, 1, 2, 'a');
	free(str);
}

void	test_char(const char* format)
{
	test(format, 'a');
	test(format, 300);
	test(format, 0);
	test(format, '\n');
	char* str = ft_strjoin2(3, "_%d_", format, "_%d_");
	test(str, 99999999, 'a', 1);
	free(str);
}
void	test_pointer(char* format)
{
	long q = INT_MAX;
	test(format, q);
	test(format, &q);
	char* str = ft_strjoin2(3, "_%d_", format, "_%s_");
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

	char* str = ft_strjoin2(3, "_%d_", format, "_%s_");
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
		test_format(ft_strjoin2(5, "%", flags, p, w, l[i]));
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

int	main()
{
#ifdef MAC_OS
	printf("mac\n");
#else
	printf("not mac\n");
#endif // _LIBCPP_VERSION



	test("%.0o", 0);//0""
	test("%.0d", 0);//0""
	test("%#.0d", 0);//0"0"
	test("%.0d", 1);//1"1"
	test_mac("%.0p", NULL);//2"0x"
	test_mac("%.0s", NULL);//0""
	test_mac("%.0p", "q");//
	test_mac("%.0s", "q");//
	test("%#.0", 0);
	test("%o", 0);
	test_mac("%.-1p", NULL);//2"0x"
	test("%lc", 1);
	test("%da%lca", 1, -1);
	test("%c", -1);
	test("%lca", -1);
	test("%#lc", -1);
	test("%#lc", 1);
	test("%#.2o", 0);
	test("%#.2o", 1);
	test("%#.0o", 0);
	test("%#2o", 0);
	test("%#-2o", 0);
	test("%#o", 0);
	//test("%Lc", 300);//1","
	test("%", -1);//0""
	test("%jjd", 1);//1"1"
	test("%llllld", 1);//1"1"
	test("%lhd", 1);//1"1"
	test("%3d", 1);//3"  1"
	test("%3)d", 1);//4"  )d"
	test("%3))d", 1);//5"  ))d"
	test("%wwwwwd", 1);//"wwwwd"
	test("%.10)d", 1);//")d"
	test("%lwd", 1);//wd
	test("%wld", 1);//wld
	//test("%c 12 %.10 cd%c", 'a', 'b');//8"a  ...%c"
	//test("%c 45 %.10 123", 'a');//5"a 45 "
	test("%c 45 %.10)", 'a');//5"a 45 )"
	test("%.10)", 1);//")"
	test("%.10123", 1);//""
	//test("%.10 123");//""
	//test("%d_%.10 123", 1);//"1_"
	test("%)", 1);//1"w"
	test("%c");//""
	test("%.1)");//""
	test("%c  ...%.10", 'a');//"a  ..."
	test("%#)", -1);//""
	test_mac("%dwww", 1);//"1wwww"
	test_mac("qqq%lswww", "ab");//""
	test_mac("12 %s 34 %s 56 %ls 78", "ab", "cd", "ef");//"12 ab 34 cd"
	test_mac("%d www%lswww", 1, "ab");//"1"
//	test("%c  ...%.   ...%c", 'a', 'b');//e:"a  ...%c"
	test_mac("w%.1w");//2"ww"
	test("w%h");//1"w"
	test("w%.1");//1"w"
	test("%wd", 1);
	test("%wld", 1);
	test("%lc", 300);//""
	test("%lc", INT_MIN);

	//return 1;

	test_mac("%03s", "ab");//"0ab"
	test_mac("% p", "ab");//"0x<address>"
	test("% s", "ab");//
	test("%   s", "ab");//
	test("%010s", NULL);
	test("%010p", NULL);
	test("%.8p", "");
	test("%p", "");
	test("%#p", "");
	test("%#.10p", "");
	test("%c", 300);
	test("%c", INT_MIN);
	test("%jd", INT_MIN);
	test("%lc", 0);
	test("%uh", -1);
	test("%ld", LONG_MIN);
	test("%ld", __LONG_LONG_MAX__);
	test("%#ld", -1);
	test("%d", 1);
	test("%ld", 1);
	//test("111%#");
	test("%02.1d", 1);
	test("%02d", 1);
	//test("%2c", 0);
	test("%-2c", 0);
	//test("%.-2d\n", 1);
	test("%d", INT_MIN);
	test("%2c", 0);
	test("%0 3d", 1);
	test("%4.2d\n", -1);
	test("%.1d", 0);
	test("%.1d", 1);
	test("%#2.0d", 0);
	test("%#2.0d", 1);
	test("%#-2.0d", 1);
	//	test("%#-2.0d", -1);
		//test("%#-2.0d", 1);
		//test("%.-1d", 1);
	test("%.2d", 1);
	test("%#-50.2d", 1);
	test("%.1c", 'a');
	test("%.10c", 'a');
	//test("%.-10c",'a');
	//test(" %.1",'a');
	//test("%.10",'a');
	test("%.-", 'a');
	test("%0 3d", 1);
	test("%#04x", 1);
	test("%#-20d", -1);
	test("%1c", 0);
	test("%2c", 'a');
	test("%5d", 1);
	test("%5d", -1);

	test("%1d", 0);
	test("%1d", 1);
	test("%1d", -1);
	test("1%");


	test("%-+##++++++------      w\n");
	test("%##++++++------      ww\n");
	test("%  w\n");

	test("%#d", -1);


	test_mac("%10s", NULL);//10"    (null)"
	test_mac("%.2s", NULL);//2"(n"
	test_mac("%.1s", NULL);//1"("
	test_mac("%.s", NULL);//0""
	test_mac("%#.-1s", NULL);//1" "
	test_mac("%#.-2s", NULL);//2"  "
	test_mac("%p", NULL);//3"0x0"
	test_mac("%10p", NULL);//2"0x"
	test_mac("%.3p", NULL);//"0x000"
	test_mac("%.1p", NULL);//"0x0"
	test_mac("%.-1p", "qqq");//"0x<addr>"
	test_mac("%.5s", NULL);//5"(null"
	test_mac("%.10s", NULL);//6"(null)"
	test_mac("%.-4s", "asd");//4"    "
	test_mac("%.-2s", "asd");//2"  "
	test_mac("%.-1s", "asd");//1" "
	test_mac("%.-1s", NULL);//1" "
	test_mac("%.6s", NULL);//6"(null)"
	test_mac( "%.-1d", 1);//6"%.0-1d"//1"1"
	test("%.p", NULL);//5"(nil)"2"0x0"
//	test("%O", 2);
//	test("%#O_", 2);
//	test("_%d_%#O_", 1, 2);
//	test("%O%d", 2,1);
//	test("%O%c", 2,'a');
////	test("%O%s", 2,"a");
	//test("%#O", 0);
	//test("%###O\n");
	//test("%####O\n");
	//test("%O", 0);
	//test("%#O", 0);
	//test("%#O", 8);
	//test("%#O", UINT_MAX);
	test("%.1s", "ab");//1"a"
	test("%.0s", "ab");//0""
	test("%.2ls", "ab");//-1""
	test("%.1ls", "ab");//-1""
	test("%.0d", 1);//
	test("%.0ls", "ab");//0""
	test("%ls", "ab");//-1""
	test("%.0s", "");//0""
	test("%.s", "");//0""
	test("%.s", "ab");//0""
	test("%.Ls", "ab");//0""
	test("%.ls", "");//0""
	test("%#.0ls", "");
	test("%.-1p", "");
	test("%.10p", NULL);//"5(nil)"
	test("%.2p", "asd");
	test("%.2p", NULL);
	test("%p", "asd");
	test("%.2p", "asd");
	test("%.2s", "asd");//2"as"
	test("%.5s", NULL);//0""
	test("%.s", NULL);//0""
	test("%.0s", NULL);//0""
	test("%#s", NULL);
	test("%lp", NULL);
	test("%p", NULL);
	test("%#lp", NULL);
	test("%ls", NULL);
	test("%s", "(null)");
	test("%s", "(nil)");
	//test("%ls", "(null)");
	//test("%ls", "(nil)");
	test("%#s", "ab");
	test("%hs", "ab");
	test("%#hs", "ab");
	test("%s", "ab");
	test("%lsw", "ab");
	test("%#ls", "ab");
	test("%s", "");
	test("%#s", "");
	test("% s", "ab");
	test("%#.3s", "ab");
	test("%#.10s", NULL);
	test("%#.10p", NULL);
	test("%#10p", NULL);

	int q;

	test("%p", &q);
	test("%d", __LONG_LONG_MAX__);
	test("%u", __LONG_LONG_MAX__);
	test("%u", UINT_MAX);

	test("%y", 0);
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
	//test("%s");
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

	//char *flags = "#+- 0";
	char* flags = "#+-0 ";
	char str[4];
	str[1] = 0;
	for (int i = 0; i < ft_strlen(flags) + 1; i++)
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

	printf("\n\n%d tests passed\n", g_tests_count);
}