/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 02:42:34 by darugula          #+#    #+#             */
/*   Updated: 2019/07/09 02:42:37 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	str_cpy(char *dest, char *src)
{
	*dest = *src;
	if (*src == 0)
	{
		return ;
	}
	str_cpy(dest + 1, src + 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	str_cpy(dest, src);
	return (dest);
}
