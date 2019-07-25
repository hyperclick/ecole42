#include "../includes/ft.h"
#include "../includes/file_processor.h"

int		validate_line(char *line, int lines_read)
{
	static int	lines_len;
	
	if (lines_read == 0)
	{
	lines_len = ft_strlen(line);
	}
	else
	{
		if ((lines_len - ft_strlen(line))!= 0)
		{
			_log("lines lengths differ\n");
			return (1);
		}
	}
	if (lines_read > get_lines_count() - 1)
	{
		_log2("map error: ambiguous line", line);
		return (1);
	}
	return (0);
}
