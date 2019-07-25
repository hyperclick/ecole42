
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

t_list	*_l(char *str, int a[])
{
	int len;
	t_list	*l = make_int_list(convert_to_int_array(a, split(str, &len, ",")), len);
	//ft_list_print_int_list	(l);
	//ft_list_print_int_list	(l);
	return 					(l);
}
t_list	*ft_list_last(t_list *begin_list);
void	test(t_list *list, t_list *expected)
{
	
	printf("\n\n-----------Test------------------\n\n\n");
	
	printf(" input list:\n" );
	ft_list_print_int_list(list);
	printf("expected:\n");
	ft_list_print_int_list(expected);
	
	printf("actual:\n");
	ft_list_print_int_list(ft_list_last(list));
}


int main(void)
{
	printf("\n\n\n\n\n-----------Tests------------------\n\n\n\n\n\n");
	
	int		a[100];
	int		b[100];
	test(_l("1,2", a),  _l("2",b));
	test(NULL, NULL);
	//ft_list_print_int_list(list);
	//qqq(list);
	//ft_list_print_int_list(l);
	//test(l,0,_l("1"));
	return (1);
	//test(NULL, 1, NULL);
	return (0);
}

