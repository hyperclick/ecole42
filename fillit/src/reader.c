#include "reader.h"
#include <fcntl.h>
#include "../libft/libft.h"
#include "tetramino.h"
#define BUFF_SIZE ((4 + 1)*(4) + 1) * sizeof(char)

t_t		*parse(char str[BUFF_SIZE], char letter)
{
	t_t	*t;
	int	i;
	int	j;

	if((t = malloc(sizeof(t_t))) == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			t->letter = letter;
			t->a[i][j] = is_empty(str[i * 5 + j]) ? EMPTY_ELEM2 : letter;
			++j;
		}
		if (str[i * 5 + j] != '\n')
		{
			free(t);
			return (NULL);
		}
		++i;
	}
	if (str[i * 5] != '\n')
	{
		free(t);
		return (NULL);
	}
	return (t);
}

BOOL	is_bad_buffer(const char buffer[BUFF_SIZE], ssize_t bytes_read)
{
	if (bytes_read == BUFF_SIZE)
	{
		return (buffer[BUFF_SIZE - 1] != '\n');
	}
	return (bytes_read != BUFF_SIZE - 1);
}

t_list	*read_file(const char	*filename)
{
	int		fd;
	t_t		*t;
	t_list	*head;
	t_list	*next;
	t_list	*current;
	char	buffer[BUFF_SIZE];
	ssize_t	bytes_read;
	char	letter;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error\n");
		exit(1);
	}
	head = NULL;
	current = NULL;
	letter = 'A';
	while ((bytes_read = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (is_bad_buffer(buffer, bytes_read) || (t = parse(buffer, letter++)) == NULL)
		{
			ft_lst_free(&head);
			ft_putstr("error\n");
			exit(2);
		}
		
		next = ft_lstnew(t, sizeof(t));
		if (next == NULL)
		{
			ft_lst_free(&head);
			ft_putstr("error\n");
			exit(3);
		}
		if (head == NULL)
		{
			current = head = next;
		}
		else
		{
			current->next = next;
			current = next;
		}
		
	}
	
	if (bytes_read != 0)
	{
		ft_lst_free(&head);
		ft_putstr("error\n");
		exit(4);
	}
	
	return (head);
}
