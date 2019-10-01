/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 01:36:50 by darugula          #+#    #+#             */
/*   Updated: 2019/07/10 01:36:53 by darugula         ###   ########.fr       */
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

int		ft_strcmp(char *s1, char *s2)
{
	if (*s1 != *s2)
	{
		return (*s1 - *s2);
	}
	if (*s1 == 0)
	{
		return (0);
	}
	return (ft_strcmp(s1 + 1, s2 + 1));
}

void	sort(int n, char *argv[])
{
	int		i;
	int		swapped;
	char	*tmp;

	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		i = 0;
		while (i < n - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				swapped = 1;
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
			}
			i++;
		}
	}
}

void	print_strings(int argc, char *argv[], int i)
{
	if (argc == 1)
	{
		return ;
	}
	ft_putstr(argv[i]);
	ft_putchar('\n');
	print_strings(argc - 1, argv, i + 1);
}

int		main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_putstr("add some args if you want me to sort them\n");
		return (1);
	}
	sort(argc - 1, argv + 1);
	print_strings(argc, argv, 1);
	return (1);
}
