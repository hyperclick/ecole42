#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "asserts.h"

void	test(const char *format, ...)
{
	char *e;
	char *a;
	int		e_r;
	int		a_r;
	int	size = 0;
	va_list argptr;

	va_start(argptr, format);
	e_r = vprintf(format, argptr);
	va_end(argptr);
	printf("\n");

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
}

int	main()
{

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
	test("",1 ,'q');
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

}