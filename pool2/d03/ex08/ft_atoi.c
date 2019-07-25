/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 04:20:27 by darugula          #+#    #+#             */
/*   Updated: 2019/07/05 04:20:32 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i++] != 0)
	{
	}
	return (i - 1);
}

int		ft_atoi(char *str)
{
	int			len;
	int			i;
	int			r;
	int			s;
	const int	max_int = 2147483648 / 10;
	int			m;

	len = ft_strlen(str);
	if (len > 10)
	{
		return (0);
	}
	m = str[0] == '-' ? -1 : 1;
	r = 0;
	i = str[0] == '-' ? 1 : 0;
	while (i < len)
	{
		if (r > max_int)
		{
			return (0);
		}
		r *= 10;
		r += str[i] - '0';
		i++;
	}
	return (r * m);
}
