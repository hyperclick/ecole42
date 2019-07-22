/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 03:09:17 by darugula          #+#    #+#             */
/*   Updated: 2019/07/09 03:09:22 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	str_n_cpy(char *dest, char *src, unsigned int n)
{
	if (n == 0)
	{
		return ;
	}
	*dest = *src;
	if (*src == 0)
	{
		return ;
	}
	str_n_cpy(dest + 1, src + 1, n - 1);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	str_n_cpy(dest, src, n);
	return (dest);
}
