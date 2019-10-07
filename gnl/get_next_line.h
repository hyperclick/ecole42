/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 00:54:32 by darugula          #+#    #+#             */
/*   Updated: 2019/09/19 00:54:34 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <unistd.h>
# define BUFF_SIZE 1

typedef struct	s_buffer
{
	int		fd;
	char	buffer[BUFF_SIZE + 1];
	char	*rest;
	char	*line;
}				t_buffer;
int				get_next_line(const int fd, char **line);
#endif
