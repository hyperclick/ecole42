#include <stdio.h>
#include "../includes/ft_list.h"

char	*extract_string(void *data)
{
	return ((char*)data);
}
void	ft_list_print_str_list(t_list *list)
{
	//printf("soon...\n");
	//printf("%p\n", list);
	while (list != NULL)
	{
		if (list->data == NULL)
		{
			printf("[(NULL)]->");
		}
		else
		{
			printf("[%s]->", extract_string(list->data));
		}
		list = list->next;
	}
	printf("(NULL)\n");
}
