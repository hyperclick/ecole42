#include "../includes/file_processor.h"
#include <stdio.h>

int	main(int argc, char **argv)
{setvbuf(stdout, NULL, _IONBF, 0);
	process_files(argc, argv);
}
