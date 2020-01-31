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
	int	size;
	va_list argptr;


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

	free(a);
	free(e);
}

int	main()
{
	test("111\n");
}