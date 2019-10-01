/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 23:16:23 by darugula          #+#    #+#             */
/*   Updated: 2019/07/09 23:16:26 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_lcase(char c)
{
	if (c <= 'z' && c >= 'a')
	{
		return (1);
	}
	return (0);
}

void	to_upper(char *str)
{
	if (*str == 0)
	{
		return ;
	}
	if (is_lcase(*str) == 1)
	{
		*str = *str + ('A' - 'a');
	}
	to_upper(str + 1);
}

char	*ft_strupcase(char *str)
{
	to_upper(str);
	return (str);
}
