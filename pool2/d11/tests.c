
#include "includes/ft_list.h"
#include "includes/ft.h"

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
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
void	test_7(t_list *list, int n, t_list *expected)
{
	
	printf("\n\n-----------Test------------------\n\n\n");
	
	printf("n = %d, input list:\n", n);
	ft_list_print_int_list(list);
	printf("expected:\n");
	ft_list_print_int_list(expected);
	
	t_list *actual = ft_list_at(list, n);
	printf("actual:\n");
	
	ft_list_print_int_list(actual);
}


void	list_clear(t_list *list);


int main(void)
{
	printf("\n\n\n\n\n-----------Tests------------------\n\n\n\n\n\n");
	
	int		a[100];
	int		b[100];
	test(NULL,3,NULL);
	test(_l("1,2,3", a),2,_l("3", b));
	test(_l("1,2,3", a),0,_l("1,2,3", b));
	test(_l("1,2,3", a),3,NULL);
	//ft_list_print_int_list(list);
	//qqq(list);
	//ft_list_print_int_list(l);
	//test(l,0,_l("1"));
	return (1);
	//test(NULL, 1, NULL);
	return (0);
}
