/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:43:51 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 11:43:52 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "tetramino.h"

#ifndef TESTS

int	main(int argc, const char *argv[])
{
	if (argc == 2)
	{
		solve(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
#endif
