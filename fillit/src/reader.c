#include "reader.h"
#include <fcntl.h>
#include "../libft/libft.h"
#include "tetramino.h"
#define BUFF_SIZE ((4 + 1)*(4 + 1) + 1) * sizeof(char)

void	ft_lst_free_item(void *item, size_t size)
{
	free(item);
}

t_t		*parse(char str[BUFF_SIZE])
{
	t_t	*t;
	int	i;
	int	j;

	t = malloc(sizeof(t_t));
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			t->a[i][j] = str[i * 4 + j];
			++j;
		}
		if (str[i * 4 + j] != '\n')
		{
			free(t);
			return (NULL);
		}
		++i;
	}
	if (str[i * 4] != '\n')
	{
		free(t);
		return (NULL);
	}
	return (t);
}

t_list	*read_file(const char	*filename)
{
	int		fd;
	t_t		*t;
	t_list	*list;
	char	buffer[BUFF_SIZE];
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error\n");
		exit(1);
	}
	while ((bytes_read = read(fd, buffer, BUFF_SIZE)) == BUFF_SIZE)
	{
		if ((t = parse(buffer)) == NULL)
		{
			ft_lstdel(&list, ft_lst_free_item);
			ft_putstr("error\n");
			exit(2);
		}
		
	}
	
	if (r != 0)
	{
		ft_putstr("error\n");
		exit(2);
	}
	
	return (list);
}
