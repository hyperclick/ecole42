/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:09:00 by darugula          #+#    #+#             */
/*   Updated: 2019/07/15 15:09:03 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char*	do_op(int argc, char **argv, char dst[]);

int		ft_strlen(char *str);

int	main(int argc, char **argv)
{
	const	int	max_int_length = 12;
	char		dst[max_int_length];
	char		*r;

	r = do_op(argc, argv, dst);
	write(1, r, ft_strlen(r));
	return (0);
}
