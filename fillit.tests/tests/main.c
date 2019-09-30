#define TESTS

#include <stdio.h>
#include "reader.h"
#include "assert.h"
#include "tetramino.h"

void	test_valid_read(const char *file_name)
{
	t_list *list = read_file(file_name);
	assert_int(4, ft_lst_count(list));
	ft_lst_free(&list);
}

int main(int argc, const char * argv[])
{
	test_valid_read("valid_sample.fillit");
	printf("Hello, World1!\n");
	return 0;
}
