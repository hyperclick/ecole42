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
	//if (ft_str_equals("env", args[0]))
	//{
	//	ft_env(count - 1, args + 1);
	//	return (TRUE);
	//}
	if (ft_str_equals("setenv", args[0]))
	{
		ft_set_env(count - 1, args + 1);
		return (TRUE);
	}
	if (ft_str_equals("unsetenv", args[0]))
	{
		ft_unset_env(count - 1, args + 1);
		return (TRUE);
	}
	return (FALSE);
}
