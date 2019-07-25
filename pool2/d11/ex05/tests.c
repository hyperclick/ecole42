
#include "../includes/ft_list.h"
#include "../includes/ft.h"

void	ft_list_print_int_list(t_list *list);


t_list	*make_int_list(int a[], int len)
{
	t_list	*list = NULL;
	t_list	*head = NULL;
	int	i = 0;
	while (i < len)
	{
		//printf("i = %d\n", i);
		if (list == NULL)
		{
			head = ft_create_elem(&a[i]);
			list = head;
		}
		else
		{
			list->next = ft_create_elem(&a[i]);
			list = list->next;
		}
		++i;
	}
	return (head);
}
t_list	*ft_create_string_elem(char *data);
t_list	*make_string_list(char *a[], int len)
{
	t_list	*list = NULL;
	t_list	*head = NULL;
	int	i = 0;
	while (i < len)
	{
		//printf("a[%d]  = '%s', &a[%d] = %p\n", i, *&a[i], i, &a[i]);
		if (list == NULL)
		{
			head = ft_create_elem((void*)a[i]);
			list = head;
		}
		else
		{
			list->next = ft_create_elem(a[i]);
			list = list->next;
		}
		++i;
	}
	return (head);
}

t_list	*_ls(char *str)
{
	int len;
	char **b = split(str, &len, ",");
	//print_string_array(b);
	t_list	*list = make_string_list( b, len);
	ft_list_print_int_list	(list);
	//ft_list_print_int_list	(l);
	return 					(list);
}

t_list	*ft_list_push_params(int ac, char **av);
void	test(char **argv, int argc, t_list *expected)
{
	
	printf("\n\n-----------Test------------------\n\n\n");
	
	printf(" input list:\n" );
	print_params(argc, argv, 0);
	printf("expected:\n");
	ft_list_print_str_list(expected);
	
	
	printf("actual:\n");
	t_list	*actual = ft_list_push_params(argc, argv);
	ft_list_print_str_list(actual);
}


int main(void)
{
	printf("\n\n\n\n\n-----------Tests------------------\n\n\n\n\n\n");
	
	char		*a[] = {
		"222",
		"111",
		"000",
	};
	
	//int len;
	//char **b = split("q,w,e", &len, ",");
	//print_string_array(b);
	//t_list	*list = make_string_list( b, len);
	
	//ft_list_print_str_list(list);
	//int		b[100];
	test(a,3,_ls("000,111,222"));
	//test(NULL);
	//ft_list_print_int_list(list);
	//qqq(list);
	//ft_list_print_int_list(l);
	//test(l,0,_l("1"));
	//test(NULL, 1, NULL);
	return (0);
}
