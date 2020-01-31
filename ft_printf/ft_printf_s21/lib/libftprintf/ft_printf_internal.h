#ifndef FT_PRINTF_INTERNAL_H

# define FT_PRINTF_INTERNAL_H

# include "libstr.h"
# include "libio.h"


int		count_tokens(const char *str);
void	fill_tokens(char **tokens, const char *str);
void	ft_printf_fill_args(va_list args_list, int count, char **args
	, char **tokens);

#endif 