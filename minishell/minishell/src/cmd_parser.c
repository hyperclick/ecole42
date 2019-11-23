
#include "minishell.h"



BOOL		built_in_processed(char * const args[], int count)
{
	if (ft_str_equals("exit", args[0]))
	{
		ft_exit(0);
	}
	if (ft_str_equals("cd", args[0]))
	{
		cd(count - 1, args + 1);
		return (TRUE);
	}
	if (ft_str_equals("env", args[0]))
	{
		ft_env(count - 1, args + 1, g_data.env);
		return (TRUE);
	}
	return (FALSE);
}