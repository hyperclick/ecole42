/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 14:08:18 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 14:08:20 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	init(argc, argv, envp);
	if (argc > 1)
	{
		cd(argc - 1, argv + 1);
	}
	while (TRUE)
	{
		print_prompt();
		process_command(read_line_hidden());
	}
}
