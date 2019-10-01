/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 01:29:36 by darugula          #+#    #+#             */
/*   Updated: 2019/07/10 01:29:39 by darugula         ###   ########.fr       */
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

void	print_params_rev(int i, char **argv)
{
	if (i == 0)
	{
		return ;
	}
	ft_putstr(argv[i]);
	ft_putchar('\n');
	print_params_rev(i - 1, argv);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("usage: a.out [params, ...]");
		ft_putchar('\n');
		return (1);
	}
	print_params_rev(argc - 1, argv);
	return (1);
}
