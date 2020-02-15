#include "ft_printf_internal.h"
#include <stdint.h>
#include <stddef.h>
#include <wchar.h>


t_fmt* hex_to_string(t_fmt* fmt, unsigned long long int p, BOOL is_upper_case)
{
	fmt->value = ft_itoa_base2(p, is_upper_case ? "0123456789ABCDEF" : "0123456789abcdef", FALSE);
	if (fmt->flags.is_alt_form)
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


t_fmt* pointer_to_string(void* p, t_fmt* fmt)
{
	fmt->flags.is_alt_form = TRUE;

	if (p == NULL)
	{
		if (fmt->precision < 0)
		{
			fmt->precision = 2;
			fmt->width = 2;
			fmt->value = ft_strdup("0x");
			fmt->type = 's';
			return (fmt);
		}
	//	fmt->value = ft_strdup("(nil)");
	//	fmt->type = 's';
	//	fmt->precision = ft_strlen(fmt->value);
	p = 0;
	}
	//else


	hex_to_string(fmt, (unsigned long long int)p, FALSE);


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
	if (fmt->precision == 0)
	{
		fmt->length[0] = 0;
	}
	return (fmt);
}



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

void parse_d(t_fmt* fmt, va_list args_list)
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
	else if (ft_strequ(fmt->length, "l") || ft_strequ(fmt->length, "L"))
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

t_fmt* char_to_string(t_fmt* fmt, long long int c)
{
	fmt->value = ft_strnew(1);
	fmt->value[0] = c;
	if ((c > 255 || c < 0) && ft_contains("tlLjz", *fmt->length))//INT_MAX)
	{
		fmt->value[0] = -1;
		//		fmt->size = -1;
	}
	return (fmt);
}

void	parse_c(t_fmt* fmt, va_list args_list)
{
	//if ((*fmt->length == 'l'))
	//{
	//	return (process_string(char_to_string(fmt, (long long int)va_arg(args_list, long long int))));
	//}
	//else
	{
		return (process_string(char_to_string(fmt, (int)va_arg(args_list, int))));
	}
}