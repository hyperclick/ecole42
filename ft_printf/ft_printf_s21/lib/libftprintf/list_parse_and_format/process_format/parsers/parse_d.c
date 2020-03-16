
#include "../../../ft_printf_internal.h"

#include <stdint.h>
#include <stddef.h>

void	parse_d(t_fmt* fmt, va_list args_list)
{

	long int v;

	if (ft_strequ(fmt->length, "h"))
	{
		v = va_arg(args_list, int);
		(process_string(int_to_string(fmt, (short int)v))); return;
	}
	else if (ft_strequ(fmt->length, "hh"))
	{
		v = va_arg(args_list, int);
		(process_string(int_to_string(fmt, (signed char)v))); return;
	}
	else if (ft_strequ(fmt->length, "l"))// || ft_strequ(fmt->length, "L"))
	{
		v = va_arg(args_list, long int);
		(process_string(int_to_string(fmt, (long int)v))); return;
	}
	else if (ft_strequ(fmt->length, "ll"))
	{
		v = va_arg(args_list, long long int);
		(process_string(int_to_string(fmt, (long long int)v))); return;
	}
	else if (ft_strequ(fmt->length, "j"))
	{
		v = va_arg(args_list, intmax_t);
		(process_string(int_to_string(fmt, (intmax_t)v))); return;
	}
	else if (ft_strequ(fmt->length, "z"))
	{
		v = va_arg(args_list, size_t);
		(process_string(int_to_string(fmt, (size_t)v))); return;
	}
	else if (ft_strequ(fmt->length, "t"))
	{
		v = va_arg(args_list, ptrdiff_t);
		(process_string(int_to_string(fmt, (ptrdiff_t)v))); return;
	}
	else
	{
		v = va_arg(args_list, long int);
		(process_string(int_to_string(fmt, (int)v))); return;
	}
}