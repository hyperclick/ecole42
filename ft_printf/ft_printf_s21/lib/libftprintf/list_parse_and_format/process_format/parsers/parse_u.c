
#include "../../../ft_printf_internal.h"

#include <stdint.h>
#include <stddef.h>

void	parse_u_process_len(t_fmt* fmt, va_list args_list, t_fmt* (to_string)(t_fmt*, unsigned long long int))
{

	unsigned long long int v;

	if (ft_strequ(fmt->length, "h"))
	{
		v = va_arg(args_list, unsigned int);
		(process_string(to_string(fmt, (unsigned short int)v))); return;
	}
	else if (ft_strequ(fmt->length, "hh"))
	{
		v = va_arg(args_list, unsigned int);
		(process_string(to_string(fmt, (unsigned char)v))); return;
	}
	else if (ft_strequ(fmt->length, "l") || ft_strequ(fmt->length, "L"))
	{
		v = va_arg(args_list, unsigned long long int);
		(process_string(to_string(fmt, (unsigned long long int)v))); return;
	}
	else if (ft_strequ(fmt->length, "j"))
	{
		v = va_arg(args_list, uintmax_t);
		(process_string(to_string(fmt, (uintmax_t)v))); return;
	}
	else if (ft_strequ(fmt->length, "ll"))
	{
		v = va_arg(args_list, unsigned long int);
		(process_string(to_string(fmt, (unsigned long int)v))); return;
	}
	else if (ft_strequ(fmt->length, "z"))
	{
		v = va_arg(args_list, size_t);
		(process_string(to_string(fmt, (size_t)v))); return;
	}
	else if (ft_strequ(fmt->length, "t"))
	{
		v = va_arg(args_list, ptrdiff_t);
		(process_string(to_string(fmt, (ptrdiff_t)v))); return;
	}
	else
	{
		v = va_arg(args_list, unsigned int);
		(process_string(to_string(fmt, (unsigned int)v))); return;
	}
}

void	parse_u(t_fmt* fmt, va_list args_list)
{
	unsigned long long int v;

	if (fmt->type == 'u')
	{
		(parse_u_process_len(fmt, args_list, uint_to_string));
	}
	else if (fmt->type == 'o')
	{
		(parse_u_process_len(fmt, args_list, oct_to_string));
	}
	else if (fmt->type == 'x')
	{
		(parse_u_process_len(fmt, args_list, little_hex_to_string));
	}
	else if (fmt->type == 'X')
	{
		(parse_u_process_len(fmt, args_list, big_hex_to_string));
	}
	else
	{
		ft_e_putstr("unexpected type\n");
		exit(8);
	}
}
