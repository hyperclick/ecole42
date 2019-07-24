#include "../includes/file_processor.h"
#include <stdio.h>
#include "../includes/ft.h"

int	main(int argc, char **argv)
{setvbuf(stdout, NULL, _IONBF, 0);
	_log("222");
	process_files(argc, argv);
}
