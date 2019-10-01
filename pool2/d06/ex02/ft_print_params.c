/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:59:14 by darugula          #+#    #+#             */
/*   Updated: 2019/07/10 00:59:16 by darugula         ###   ########.fr       */
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

void	print_params(int argc, char **argv, int i)
{
	if (argc == 0)
	{
		return ;
	}
	ft_putstr(argv[i]);
	ft_putchar('\n');
	print_params(argc - 1, argv, i + 1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("usage: a.out [params, ...]");
		ft_putchar('\n');
		return (1);
	}
	print_params(argc - 1, argv, 1);
	return (1);
}
