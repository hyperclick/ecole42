/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 14:01:55 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 14:01:56 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static BOOL	handle_old_work_dir(char folder[PATH_MAX])
{
	static char	old_work_dir[PATH_MAX] = "";

	if (ft_strequ("-", folder))
	{
		if (ft_strlen(old_work_dir) == 0)
		{
			ft_e_putstr("-minishell: cd: OLDPWD not set\n");
			return (FALSE);
		}
		debug_printf("old_work_dir = '%s'\n", old_work_dir);
		ft_strcpy(folder, old_work_dir);
		debug_printf("exec cd '%s'\n", folder);
		ft_putstr(folder);
		ft_putstr("\n");
	}
	getcwd(old_work_dir, PATH_MAX - 1);
	return (TRUE);
}

void		cd(int argc, char *const argv[])
{
	char		folder[PATH_MAX];

	if (argc > 1)
	{
		ft_e_putstr("-minishell: cd: too many arguments\n");
		return ;
	}
	ft_strcpy(folder, (argc == 0) ? env_get_value("HOME") : argv[0]);
	debug_printf("exec cd '%s'\n", folder);
	if (!handle_old_work_dir(folder))
	{
		return ;
	}
	if (chdir(folder) != 0)
	{
		ft_e_putstr("-minishell: cd: ");
		ft_e_putstr(folder);
		ft_e_putstr(": No such file or directory\n");
		return ;
	}
	debug_printf("new curdir = %s\n", getcwd(folder, PATH_MAX));
}
