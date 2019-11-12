#include <stdio.h>
#include "ls.h"
int	main2(int argc, const char* argv[]);

void    use_listattr(const char filename[])
{
	
	char list[XATTR_SIZE], value[XATTR_SIZE];
	ssize_t listLen, valueLen;
	listLen = listxattr(filename, list, XATTR_SIZE, XATTR_NOFOLLOW);
	
	/* Loop through all EA names, displaying name + value */
	
	for (int ns = 0; ns < listLen; ns += strlen(&list[ns]) + 1)
	{
		printf("        name=%s; ", &list[ns]);
		
		valueLen = getxattr(filename, &list[ns], value, XATTR_SIZE, 0, XATTR_NOFOLLOW);
		if (valueLen == -1) {
			printf("couldn't get value");
		} else  {
			printf("value=%.*s", (int) valueLen, value);
		}
		
		printf("\n");
	}
	
}
int main2(int argc, const char * argv[])
{
	//use_listattr("log.txt");
	main2(argc, argv);
	
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
