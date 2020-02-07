#include "ft_printf_internal.h"

BOOL	is_signed_number(char t)
{
	return (ft_contains("idaAeEfFgG", t));
}

BOOL	is_number(char t)
{
	return (ft_contains("uoxX", t) || is_signed_number(t));
}

BOOL	is_int_number(char t)
{
	return (ft_contains("uoxXid", t));
}

BOOL	is_valid_type(char t)
{
	return (is_number(t) || ft_contains("pcs", t));
}