/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:17:30 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:17:32 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
