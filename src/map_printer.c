#include "../includes/ft.h"
#include "../includes/t_table.h"
#include "../includes/file_processor.h"

#include <stdio.h>

char	g_tmp[100];
int		g_lines_read = -1;

void	draw_line_with_bsq(char *line)
{
	int x;
	t_section bsq;
	
	bsq = get_bsq();
	//printf("line '%s' (%s)\n", line, sec_to_string(g_tmp, &bsq));
	x = -1;
	while (line[++x] != 0)
	{
		if (x >= bsq.x && x < bsq.x + bsq.len)
		{
			//printf("x = %d\n", x);
			ft_putchar(get_full());
		}
		else
		{
			ft_putchar(line[x]);
		}
	}
	new_line();
}


int		process_line_to_print_bsq(char *line, int line_number)
{
	int		r;
	t_section bsq;
	
	bsq = get_bsq();
	
	r = 0;
	
	g_lines_read = line_number - 1;
	//printf("line %d: '%s' (%s)\n", g_lines_read, line, sec_to_string(g_tmp, &bsq));
	if (g_lines_read == -1)
	{
		return (0);
	}
	
	if (g_lines_read < bsq.y || g_lines_read > bsq.y + bsq.len)
	{
		ft_putstr(line);
		new_line();
		return (0);
	}
	draw_line_with_bsq(line);
	
	return (0);
}
