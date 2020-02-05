#include "ft_printf_internal.h"

BOOL	is_signed_number(char t)
{
	return (ft_contains("iduaAeAfFgG", t));
}

BOOL	is_number(char t)
{
	return (ft_contains("oxX", t) || is_signed_number(t));
}

BOOL	is_valid_type(char t)
{
	return (ft_contains("diflpcsuxXoaAeEfFgG", t));
}