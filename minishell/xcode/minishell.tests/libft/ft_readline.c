/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 15:16:56 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 15:16:58 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_readline(char *dst, int size)
{
	char ch;

	while (read(STDIN_FILENO, &ch, 1) > 0)
	{
		if (--size == 0)
		{
			ft_e_putstr("buffer is too small");
			exit(1);
		}
		if (ch == '\n')
		{
			break ;
		}
		*dst++ = ch;
	}
	*dst = 0;
}
