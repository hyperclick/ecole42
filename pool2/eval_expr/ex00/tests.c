#include <stdio.h>
#include "includes/ft.h"
#include <stdlib.h>
#include "includes/state.h"

void	print_state(struct s_state s)
{
	char	*stack[] = {"?","?","?","?","?"};
	char	a[15];
	char	o1[2];
	char	b[15];
	char	o2[2];
	char	c[15];
	char	r[15];
	char	*tmp;
	
	print_dup(" ", s.input.i);
	ft_putstr("*i = ");
	ft_putnbr(s.input.i);
	ft_putstr(": ");
	ft_putstr(", str = '");
	if (s.input.str == NULL || s.input.str[s.input.i] == NULL)
	{
		ft_putstr("(NULL)");
	}
	else
	{
		ft_putstr(s.input.str[s.input.i]);
	}
	ft_putstr("' ");
	stack[0] = !is_operand_set(s.operands[0]) ? "a" : ft_itoa(s.operands[0],a);
	o1[0] = s.operators[0];
	o1[1] = 0;
	stack[1] = o1;
	stack[2] = !is_operand_set(s.operands[1]) ? "b" : ft_itoa(s.operands[1], b);
	o2[0] = s.operators[1];
	o2[1] = 0;
	stack[3] = o2;
	stack[4] = !is_operand_set(s.operands[2]) ? "c" : ft_itoa(s.operands[2], c);
	ft_putstr(" ");
	ft_putstr(stack[0]);
	ft_putstr(" ");
	ft_putstr(stack[1]);
	ft_putstr(" ");
	ft_putstr(stack[2]);
	ft_putstr(" ");
	ft_putstr(stack[3]);
	ft_putstr(" ");
	ft_putstr(stack[4]);
	tmp = !is_operand_set(s.result) ? "?" : ft_itoa(s.result, r);
	ft_putstr(" result = ");
	ft_putstr(tmp);
	ft_putstr("\n");
}

int eval_expr(char *str);

void	test(char* str, int expected)
{
	printf("\n\n--------------test start [%s]--------------------\n\n", str);
	//printf("'%s' = %d = ", str, expected);
	int actual = eval_expr(str);
	//printf("%d\n", actual);
	printf("actual:\t\t%d\n", actual);
	printf("expected:\t%d\n", expected);	if (actual != expected)
	{
		printf("fail:\nstr:\t'%s'\nexpected:\t%d\nactual:\%d\n", str, expected, actual);
		exit(1);
	}
	printf("\n\n--------------test end [%s]--------------------\n\n", str);
}


int main(int ac, char **av)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("\n\n\n\n==============tests started=================\n\n\n\n");
	/*
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
	*/
	/*
	int len;
	
	char **a = split_char(split_char(split("(1)", &len, " \t"), '('), ')');
	print_string_array(a);
	return 0;
	*/
	test(" \t ", 0);
	test("1", 1);
	
	test(NULL, 0);
	test("", 0);
	test(" \t 1", 1);
	test(" 2 \t", 2);
	test("1   ", 1);
	test("+1", 1);
	test("+ 1  2", INT_MIN);
	test("1 +", INT_MIN);
	test("1 + 2 +", INT_MIN);
	
	test("1 + 2", 3);
	test("1 + 2 * 3", 7);
	test("1 * 2 + 3", 5);
	test("1 + -2", -1);
	
	test("(1)", 1);
	test("((1))", 1);
	
	test("1 + (2)", 3);
	
	test("1 + (2 + 3)", 6);
	
	test("1 / 2", 0);
	test("1 / -2", 0);
	test("4 / -2", -2);
	test("1 % 2", 1);
	test("1 - 2 - (-3)", 2);
	test("((((((((((                                   1 +                                 (-1))))))))))", 0);
	test("(5 + ((3 * 4) - 2))", 15);
	test("5 % (5 % 3) % 5", 1);
	test("3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 1", 4);
	
	
	test(" -1", -1);
	test("-2", -2);
	test("-10", -10);
	test("- 42", -42);
	
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	//test("1+2", 3);
	printf("\n\n\n\n============all tests finished================\n\n\n\n");
	return (0);
	
	
	return 0;
	return 0;
	return 0;
	return 0;
	return 0;
	
	test("(", 0);
	return 0;
	return 0;
	
	printf("\n\n\n\n============all tests finished================\n\n\n\n");
	return (0);
}
