
#include "minishell.h"

BOOL		is_exit(const char str[MAX_CMD_LINE])
{
	return (ft_str_equals("exit", ft_strtrim(str)));
}

BOOL		built_in_processed(const char str[MAX_CMD_LINE])
{
	if (is_exit(str))
	{
		//printf("exiting\n");
		exit(0);
	}
	return (FALSE);
}