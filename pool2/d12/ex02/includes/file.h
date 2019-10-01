/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:26:58 by darugula          #+#    #+#             */
/*   Updated: 2019/07/18 19:27:00 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

void	read_file(int fd);
void	print_stream(int fd, int offset);
int		print_file_tail(char *fname, int offset, BOOL print_file_name);
int		print_file_tails(int argc, char *argv[], int i, int offset);

#endif
