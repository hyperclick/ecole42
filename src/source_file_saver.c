#include "../includes/ft.h"
#include "../includes/t_table.h"
#include "../includes/file_processor.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


char	g_tmp[100];

char	*src_get_file_name(void)
{
	return "src.txt";
}

int		src_recreate(void)
{
	int		fd;
	
	fd = open(src_get_file_name(),
			  O_TRUNC, S_IRUSR | S_IWUSR |
			  S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fd == -1)
	{
		_log2("map error: failed to open file:\t", src_get_file_name());
		return (-1);
	}
	return(close(fd));
}

int		src_save_line(char *line)
{
	int		fd;

	fd = open(src_get_file_name(),
			  O_WRONLY | O_APPEND | O_CREAT, S_IRUSR |
			  S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if (fd == -1)
	{
		_log2("map error: failed to open file:\t", src_get_file_name());
		return (-1);
	}
	
	print_to_out(fd, line);
	print_to_out(fd, "\n");
	close(fd);
	return (0);
}

