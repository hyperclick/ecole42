#include "ft_printf_internal.h"


t_fmt* hex_to_string(long long p, BOOL is_upper_case, t_fmt* fmt)
{
	fmt->value = ft_itoa_base(p, is_upper_case ? "0123456789ABCDEF" : "0123456789abcdef");
	if (fmt->flags.is_alt_form && p != 0)
	{
		fmt->prefix = ft_strdup(is_upper_case ? "0X" : "0x");
	}
	return (fmt);
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
		hex_to_string((long long)p, FALSE, fmt);
	}
	return (fmt);
}

t_fmt* oct_to_string(uint p, t_fmt* fmt)
{
	fmt->value = ft_itoa_base(p, "01234567");
	if (fmt->flags.is_alt_form && p != 0)
	{
		fmt->value = ft_str_prepend_and_free("0", fmt->value);
	}
	return (fmt);
}

t_fmt* int_to_string(t_fmt* fmt, long int n)
{
	ulong long	u;
	
	u = n;
	if (n < 0)
	{
		fmt->prefix = ft_strdup("-");
		u = -(uint)n;
	}
	fmt->value = ft_itoa(u);
	return (fmt);
}

t_fmt* uint_to_string(t_fmt* fmt, uint n)
{
	fmt->value = ft_itoa(n);
	return (fmt);
}

t_fmt* pchar_to_string(t_fmt* fmt, const char* str)
{
	fmt->value = ft_strdup(str == NULL ? "(null)" : str);
	return (fmt);
}

t_fmt* char_to_string(t_fmt* fmt, char c)
{
	fmt->value = ft_strnew(1);
	fmt->value[0] = c;
	return (fmt);
}