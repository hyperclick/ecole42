
#include "minishell.h"

BOOL		is_exit(const char str[MAX_CMD_LINE])
{
	return (ft_str_equals("exit", ft_strtrim(str)));
}