#include "ft_printf_internal.h"
#include <stdint.h>
#include <stddef.h>
#include <wchar.h>


t_fmt* hex_to_string(t_fmt* fmt, unsigned long long int p, BOOL is_upper_case)
{
	fmt->value = ft_itoa_base2(p, is_upper_case ? "0123456789ABCDEF" : "0123456789abcdef", FALSE);
	if (fmt->flags.is_alt_form && p != 0)
	{
		fmt->prefix = ft_strdup(is_upper_case ? "0X" : "0x");
	}
	return (fmt);
}

t_fmt* little_hex_to_string(t_fmt* fmt, unsigned long long int p)
{
	return(hex_to_string(fmt, p, FALSE));
}

t_fmt* big_hex_to_string(t_fmt* fmt, unsigned long long int p)
{
	return(hex_to_string(fmt, p, TRUE));
}


t_fmt	*pointer_to_string(void* p, t_fmt* fmt)
{
	fmt->flags.is_alt_form = TRUE;
	if (p == NULL)
	{
		fmt->value = ft_strdup("(nil)");
	}
	else
	{
		hex_to_string((unsigned long long)p, FALSE, fmt);
	}
	return (fmt);
}

t_fmt* oct_to_string(t_fmt* fmt, unsigned long long int n)
{
	fmt->value = ft_itoa_base2(n, "01234567", FALSE);
	//if (fmt->flags.is_alt_form && n != 0)
	if (fmt->flags.is_alt_form)
	{
		fmt->prefix = ft_strdup("0");
	}
	return (fmt);
}

t_fmt* int_to_string(t_fmt* fmt, long int n)
{
	unsigned long int	u;
	
	u = n;
	if (n < 0)
	{
		fmt->prefix = ft_strdup("-");
		u = -(unsigned long int)n;
	}
	fmt->value = ft_uitoa(u);
	return (fmt);
}

t_fmt* uint_to_string(t_fmt* fmt, unsigned long long int n)
{
	fmt->value = ft_uitoa(n);
	return (fmt);
}

t_fmt* pchar_to_string(t_fmt* fmt, const char* str)
{
	fmt->value = ft_strdup(str == NULL ? "(null)" : str);
	return (fmt);
}



char* parse_u_process_len(t_fmt* fmt, va_list args_list, t_fmt*(to_string)(t_fmt*, unsigned long long int))
{

	unsigned long long int v;

	if (ft_strequ(fmt->length, "h"))
	{
		v = va_arg(args_list, unsigned int);
		return (process_string(to_string(fmt, (unsigned short int)v)));
	}
	else if (ft_strequ(fmt->length, "hh"))
	{
		v = va_arg(args_list, unsigned int);
		return (process_string(to_string(fmt, (unsigned char)v)));
	}
	else if (ft_strequ(fmt->length, "l") || ft_strequ(fmt->length, "L"))
	{
		v = va_arg(args_list, unsigned long long int);
		return (process_string(to_string(fmt, (unsigned long long int)v)));
	}
	else if (ft_strequ(fmt->length, "j"))
	{
		v = va_arg(args_list, uintmax_t);
		return (process_string(to_string(fmt, (uintmax_t)v)));
	}
	else if (ft_strequ(fmt->length, "ll"))
	{
		v = va_arg(args_list, unsigned long int);
		return (process_string(to_string(fmt, (unsigned long int)v)));
	}
	else if (ft_strequ(fmt->length, "z"))
	{
		v = va_arg(args_list, size_t);
		return (process_string(to_string(fmt, (size_t)v)));
	}
	else if (ft_strequ(fmt->length, "t"))
	{
		v = va_arg(args_list, ptrdiff_t);
		return (process_string(to_string(fmt, (ptrdiff_t)v)));
	}
	else
	{
		v = va_arg(args_list, unsigned int);
		return (process_string(to_string(fmt, (unsigned int)v)));
	}
}


char* parse_u(t_fmt* fmt, va_list args_list)
{

	unsigned long long int v;

	if (fmt->type == 'u')
	{
		return (parse_u_process_len(fmt, args_list, uint_to_string));
	}
	else if (fmt->type == 'o')
	{
		return (parse_u_process_len(fmt, args_list, oct_to_string));
	}
	else if (fmt->type == 'x')
	{
		return (parse_u_process_len(fmt, args_list, little_hex_to_string));
	}
	else if (fmt->type == 'X')
	{
		return (parse_u_process_len(fmt, args_list, big_hex_to_string));
	}
	else
	{
		ft_e_putstr("unexpected type\n");
		exit(8);
	}
}

char* parse_d(t_fmt *fmt, va_list args_list)
{

	long int v;

	if (ft_strequ(fmt->length, "h"))
	{
		v = va_arg(args_list, int);
		return (process_string(int_to_string(fmt, (short int)v)));
	}
	else if (ft_strequ(fmt->length, "hh"))
	{
		v = va_arg(args_list, int);
		return (process_string(int_to_string(fmt, (signed char)v)));
	}
	else if (ft_strequ(fmt->length, "l") || ft_strequ(fmt->length, "L"))
	{
		v = va_arg(args_list, long int);
		return (process_string(int_to_string(fmt, (long int)v)));
	}
	else if (ft_strequ(fmt->length, "ll"))
	{
		v = va_arg(args_list, long long int);
		return (process_string(int_to_string(fmt, (long long int)v)));
	}
	else if (ft_strequ(fmt->length, "j"))
	{
		v = va_arg(args_list, intmax_t);
		return (process_string(int_to_string(fmt, (intmax_t)v)));
	}
	else if (ft_strequ(fmt->length, "z"))
	{
		v = va_arg(args_list, size_t);
		return (process_string(int_to_string(fmt, (size_t)v)));
	}
	else if (ft_strequ(fmt->length, "t"))
	{
		v = va_arg(args_list, ptrdiff_t);
		return (process_string(int_to_string(fmt, (ptrdiff_t)v)));
	}
	else
	{
		v = va_arg(args_list, long int);
		return (process_string(int_to_string(fmt, (int)v)));
	}
}

t_fmt* char_to_string(t_fmt* fmt, wint_t c)
{
	fmt->value = ft_strnew(1);
	fmt->value[0] = c;
	return (fmt);
}

char* parse_c(t_fmt* fmt, va_list args_list)
{
	if (ft_strequ(fmt->length, "l"))
	{
		return (process_string(char_to_string(fmt, (wint_t)va_arg(args_list, wint_t))));
	}
	else
	{
		return (process_string(char_to_string(fmt, (int)va_arg(args_list, int))));
	}
}