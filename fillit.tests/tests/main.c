#define TESTS

#include <stdio.h>
#include "assert.h"
#include "tetramino.h"
#include "result_checks.h"

void	test_valid_read(const char *file_name)
{
	read_file(file_name);
	assert_int(4, get_figures_count());
}




int main(int argc, const char * argv[])
{
	test_valid_read("valid_sample.fillit");
	solve("valid_5");
	
	//solve("valid_sample.fillit");
	
	//solve("valid_sample.fillit");
	
	
	
	
	printf("Hello, World1!\n");
	return 0;
}
