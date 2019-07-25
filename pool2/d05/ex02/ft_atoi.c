/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 01:51:27 by darugula          #+#    #+#             */
/*   Updated: 2019/07/09 01:51:31 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		is_digit(char c)
{
	return (c > '0' && c <= '9') ? 1 : 0;
}

int		is_number(char *str)
{
	while (*str != 0)
	{
		if (is_digit(*str) == 0)
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i++] != 0)
	{
	}
	return (i - 1);
}

int		atoi2(char *str, int n)
{
	int digit;

	if (*str == 0)
	{
		return (n);
	}
	digit = *str - '0';
	str++;
	n = 10 * n + digit;
	return (atoi2(str, n));
}

int		ft_atoi(char *str)
{
	int			is_negative;
	const int	max_int_len = 12;

	if (ft_strlen(str) > max_int_len)
	{
		return (-1);
	}
	is_negative = *str == '-' ? 1 : 0;
	if (is_negative == 1)
	{
		str++;
	}
	if (*str == 0)
	{
		return (0);
	}
	if (!is_number(str))
	{
		return (0);
	}
	return (is_negative ? -atoi2(str, 0) : atoi2(str, 0));
}
