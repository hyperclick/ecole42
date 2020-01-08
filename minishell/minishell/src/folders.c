/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   folders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:29:04 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:29:06 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**fill_path_folders(void)
{
	const char	*path;
	int			count;
	char		**folders;

	path = env_get_value("PATH");
	count = (path == NULL) ? 0 : ft_count_words(path, ":");
	folders = (char**)malloc((sizeof(char*)) * (count + 1));
	folders[count] = NULL;
	ft_split(folders, path, count, ":");
	return (folders);
}
