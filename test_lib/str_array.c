#include <stdio.h>
# include <stdlib.h>
#include <string.h>

void	print_string_array(char *a[], int count)
{
	if (a == NULL)
	{
		printf("NULL array");
		return ;
	}
	int	i = -1;
	printf("[");
	while (++i < count)
	{
		printf("'%s'", a[i]);
		if (i != count - 1)
		{
			printf(", ");
		}
	}
	printf("]\n");
}

void	print_zero_terminated_string_array(char *a[])
{
	if (a == NULL)
	{
		printf("NULL array");
		return ;
	}
	int	count = 0;
	while (a[count])
		//while (a[count] != NULL)
	{
		count++;
	}
	print_string_array(a, count);
}
