/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:59:14 by darugula          #+#    #+#             */
/*   Updated: 2019/07/10 01:08:16 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putstr(char *str)
{
	if (*str == 0)
	{
		return ;
	}
	ft_putchar(*str);
	ft_putstr(str + 1);
}

int		main(int argc, char **argv)
{
	ft_putstr(argv[0]);
	ft_putchar('\n');
}
