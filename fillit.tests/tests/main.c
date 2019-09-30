#define TESTS

#include <stdio.h>
#include "../../fillit/src/reader.h"

int main(int argc, const char * argv[])
{
	read_file("valid_sample.fillit");
	printf("Hello, World1!\n");
	return 0;
}
