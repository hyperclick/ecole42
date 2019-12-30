/*_**************************************************************************_*/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/*_**************************************************************************_*/

#include "libft.h"
#include <stdio.h>

void	log_log(const char *str)
{
	FILE	*fp;

	fp = fopen("log.txt", "a");
	fprintf(fp, "%s", str);
	fclose(fp);
}

void	log_line(const char *str)
{
	log_log(str);
	log_log("\n");
}
