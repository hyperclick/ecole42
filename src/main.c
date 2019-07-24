#include "../includes/file_processor.h"
#include <stdio.h>
#include "../includes/ft.h"

int	main(int argc, char **argv)
{setvbuf(stdout, NULL, _IONBF, 0);
	//printf("\n\n\n========argv[%d] = '%s'\n", argc - 1, argv[argc - 1]);
	process_files(argc, argv);
}
