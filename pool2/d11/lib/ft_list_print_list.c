#include <stdio.h>
#include "../includes/ft_list.h"

int		extract_int(void *data)
{
	return (*((int*)data));
}
void	ft_list_print_int_list(t_list *list)
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
			printf("[%d]->", extract_int(list->data));
		}
		list = list->next;
	}
	printf("(NULL)\n");
}
