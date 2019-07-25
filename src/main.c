#include <fcntl.h>
#include <unistd.h>
#include "../includes/file_processor.h"
#include "../includes/ft.h"

int		load(int fd, int step)
{
	const int	buffer_length = 999999;
	char		buffer[buffer_length];
	char		rest[buffer_length];
	int			bytes_read;
	int			r;
	
	bytes_read = read(fd, buffer, buffer_length);
	if(bytes_read == 0)
	{
		_log("map error: empty file");
		return (1);
	}
	while (bytes_read != 0)
	{
		buffer[bytes_read] = 0;
		r = process_buffer(rest, buffer, bytes_read, step);
		if (r != 0)
		{
			return (r);
		}
		bytes_read = read(fd, buffer, buffer_length);
	}
	return (0);
}

int		load_file(char *name, BOOL from_console)
{
	int	fd;
	int	r;
	if (!from_console)
	{
		fd = open(name, O_RDONLY);
		if (fd == -1)
		{
			_log("map error: failed to open file:");
			_log(name);
			return (-1);
		}
	}
	r = load(from_console ? 0 : fd, 0);
	if(!from_console)
	close(fd);
	if (r != 0)
	{
		_log2("map error: failed to read file:", name);
		return (-1);
	}
	return (0);
}
int	process_file(char *name, BOOL from_console)
{
	int			fd;
	int			r;
	
	src_recreate();
	if (load_file(name, from_console))
	return (1);
	all_table_clean();
	fd = open(src_get_file_name(), O_RDONLY);
	if (fd == -1)
	{
		_log2("map error: failed to open file:", name);
		return (-1);
	}
	r = load(fd, 1);
	close(fd);
	if (r != 0)
	{
		_log("map error: failed to open file:");
		_log(name);
		return (-1);
	}
	clear_bsq();
	return (r);
}

int	main(int argc, char **argv)
{
	BOOL	from_console;
	int	i;
	int	r;
	
	from_console = FALSE;
	if (argc == 1)
	{
		argc = 2;
		from_console = TRUE;
	}
	i = 1;
	while (i < argc)
	{
		r = process_file(argv[i], from_console);
		if (r != 0)
		ft_putstr("map error\n");
		if (argc > 2)
		{
			ft_putchar('\n');
		}
		++i;
	}
	_log("finished");
}

