#include "../includes/ft.h"
#include "../includes/t_table.h"
#include "../includes/file_processor.h"
#include <fcntl.h>
#include <unistd.h>

char	g_tmp[100];

int		validate_line_number(int line_number, char *line)
{
	if (line_number == 0)
	{
		_log2("map error: no new_line in file", line);
		return (1);
	}
	if (line_number < get_lines_count() + 1)
	{
		_log("map error: missing line(s)");
		return (1);
	}
	return (0);
}

int		process_lines(char *total,  int step, char *buffer4line)
{
	int	r;
	char *line;
	int			line_number;
	
	line = buffer4line;
	line_number = 0;
	while (*total != 0)
	{
		if (*total == '\n')
		{
			*line = '\0';
			total++;
			r = (step == 0) ? process_line(buffer4line, (line_number)++) :
			process_line_to_print_bsq(buffer4line, (line_number)++);
			if (r != 0)
				return (r);
			line = buffer4line;
		}
		if (*total == '\n')
			continue;
		*line++ = *total++;
	}
	*line = '\0';
	return (validate_line_number(line_number, line));
}

int		process_buffer(char *rest, char *buffer, int buffer_length, int step)
{
	char		buffer4total[2 * buffer_length];
	char		buffer4line[2 * buffer_length];
	char		*total;
	
	total = buffer4total;
	ft_concat(total, rest, buffer);
	if (process_lines(total, step, buffer4line) != 0)
		return 1;
	
	ft_strcpy(rest, buffer4line);
	return (0);
}



