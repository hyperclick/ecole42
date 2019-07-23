#include "../includes/ft.h"
#include "../includes/t_table.h"
#include "../includes/file_processor.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_concat(char *dst, char *a, char *b)
{
	ft_strcpy(dst, a);
	ft_strcpy(dst + ft_strlen(a), b);
	
	return (dst);
}

int		process_line(char *line)
{
	printf("'%s'\n", line);
	return (0);
}

int		process_buffer(char *rest, char *buffer, int buffer_length)
{
	int			r;
	char		buffer4total[2*buffer_length];
	char		*total;
	char		buffer4line[2*buffer_length];
	char		*line;
	
	printf("rest = '%s'\n", rest);
	//printf("buffer = '%s'\n", buffer);
	
	total = buffer4total;
	ft_concat(total, rest, buffer);
	
	//printf("total len = %d, total = '%s'\n", ft_strlen(total), total);
	
	line = buffer4line;
	while (*total != 0)
	{
		
		if (*total == '\n')
		{
			*line = '\0';
			total++;
			//printf("line = '%s'\n", buffer4line);
			r = 0;
			//r = check_line(buffer4line, line - buffer4line);
			if (r != 0)
			{
				_log("lines lengths differ\n");
				return (r);
			}
			process_line(buffer4line);
			line = buffer4line;
			continue;
		}
		
		*line++ = *total++;
	}
	
	*line = '\0';
	ft_strcpy(rest, line);
	return (0);
}


int		load(int fd)
{
	const int	buffer_length = 100;
	char		buffer[buffer_length];
	char		rest[buffer_length];
	int			bytes_read;
	int			r;
	
	bytes_read = read(fd, buffer, buffer_length);
	while (bytes_read != 0)
	{
		buffer[bytes_read] = 0;
		r = process_buffer(rest, buffer, bytes_read);
		if (r != 0)
		{
			return (r);
		}
		//write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, buffer_length);
	}
	
	return (0);
}

int		print_echo(int fout, int fin)
{
	const int	buffer_length = 1000000;
	char		buffer[buffer_length];
	int			bytes_read;

	bytes_read = read(fin, buffer, buffer_length);
	while (bytes_read != 0)
	{
		print_to_out(fout, buffer);
		bytes_read = read(fin, buffer, buffer_length);
	}
	return (0);
}

int	process_file(char *name)
{
	int			fd;
	int			r;
	
	printf("\n\n\n\n\nprocess file: '%s'\n\n\n\n\n", name);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (-1);
	r = load(fd);
	close(fd);
	return (r);
}

void	process_files(int argc, char **argv)
{
	printf("\n\n\n\n\n ==================       process files =================== \n\n\n\n\n");
	_log("started");
	/*
	t_section	s = {0,0,0};
	t_table *t = table_create(&s);
	t_section	s1 = {0,0,1};
	table_append(t, &s1);
	t_section	s2 = {0,1,0};
	table_append(t, &s2);
	char	tmp[100];
	sec_to_string(tmp, &s);
	//printf("%s\n", tmp);
	table_print_all(t);
	table_clean_all(t);
	*/
	
	
	
	//return ;
	int	i;
	int	r;
	//todo: handle no args
	i = 1;
	while (i < argc)
	{
		r = process_file(argv[i]);
		if (r != 0)
		{
			ft_putstr("map error\n");
		}
		if (argc > 2)
		{
			ft_putchar('\n');
		}
		++i;
	}
	printf("m_get_count = %d\n", m_get_count() );
	_log("finished");
}
