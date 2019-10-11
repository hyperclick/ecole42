#include <stdio.h>
#include "ls.h"

g_input		parse(const char *str)
{
	g_input	r;
	r.find.pattern[0]=0;
	return (r);
}


void	ls(const char *str)
{
	g_input	input = parse(str);
	//print(format(sort(find(input.search_string, input.find), input.sort), input.format), input.print);
}


int main(int argc, const char * argv[])
{
	
		ls("");
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
