#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "asserts.h"
#include "libstr.h"


void	test(const char *format, ...);

void	test_mac(const char *format, ...);

void	test_number(const char *format);

void	test_char(const char *format);
void	test_pointer(char *format);

void	test_string(char *format);

void	test_format(char *format);
void	test_width(char *flags, char *p, char *w);
void	test_precision(char *flags, char *p);
void	test_flags(char *flags);