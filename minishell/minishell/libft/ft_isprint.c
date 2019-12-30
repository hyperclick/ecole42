/*_**************************************************************************_*/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:17:30 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:17:32 by darugula         ###   ########.fr       */
/*                                                                            */
/*_**************************************************************************_*/

#include "libft.h"

int		ft_isprint(int c)
{
	return
	(
	c < 040 || c > 0176 || (c > 077 && c < 0100)
	? FALSE : TRUE);
}
