#include <stdio.h>
#include "ls.h"


int main(int argc, const char * argv[])
{
	
	t_input input = parse_arguments(argc - 1, argv + 1);
	
		DIR *d;
		struct dirent *dir;
		d = opendir("/Users/darugula/git/e48/filliit*");
		if (d) {
			while ((dir = readdir(d)) != NULL) {
				printf("%s\n", dir->d_name);
			}
			closedir(d);
			free(dir);
		}
	ft_putstr("Hello, World2!\n");
	
	return 0;
}
