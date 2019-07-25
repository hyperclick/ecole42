/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 22:01:34 by darugula          #+#    #+#             */
/*   Updated: 2019/07/14 22:01:36 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		solve_sudoku(char *argv[]);
void	print(void);

void	print_element(int b[9][9], int i, int j, int len)
{
	if (b[i][j] == 0)
	{
		put_char('.');
	}
	else if (b[i][j] == 10)
	{
		put_char('?');
	}
	else
	{
		put_digit(b[i][j]);
	}
	if (j != len - 1)
	{
		put_char(' ');
	}
}

void	print_array(int b[9][9], int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			print_element(b, i, j, len);
			++j;
		}
		put_char('\n');
		++i;
	}
}

int		verify_strings(char **strings)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (str_len(strings[i]) != 9)
		{
			put_str("Error\n");
			return (1);
		}
		++i;
	}
	return (0);
}

int		handle_result(int r)
{
	if (r != 0)
	{
		put_str("Error\n");
	}
	else
	{
		print();
	}
	return (r);
}

int		main(int argc, char **argv)
{
	int		r;
	char	*strings[9];
	int		i;

	if (argc != 10)
	{
		put_str("Error\n");
		return (1);
	}
	i = 0;
	while (i < 9)
	{
		strings[i] = argv[i + 1];
		++i;
	}
	r = verify_strings(strings);
	if (r != 0)
	{
		put_str("Error\n");
		return (r);
	}
	r = solve_sudoku(strings);
	return (handle_result(r));
}
