/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:48:58 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:48:59 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		log_input(t_input input)
{
	int	i;

	log_line("arguments parsed:");
	log_line("files:");
	i = -1;
	while (++i < input.files_count)
	{
		log_line(input.files[i].full_name.path);
	}
	log_line("folders:");
	i = -1;
	while (++i < input.folders_count)
	{
		log_line(input.folders[i].full_name.path);
	}
}

int			main(int argc, const char *argv[])
{
	t_input	input;

	log_line("\n\n\n---------------started----------------");
	log_line(argv[0]);
	input = parse_arguments(argc - 1, argv + 1);
	log_input(input);
	print_entries(
		sort(input.files, input.files_count, input.sort_options)
		, input.files_count
		, input.print_options);
	print_folders(
		sort(input.folders, input.folders_count, input.sort_options)
		, input.folders_count
		, input);
	return (0);
}
