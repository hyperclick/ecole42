#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

void	create_directory(char *path)
{
	
	DIR* dir = opendir(path);
	if (dir) {
		/* Directory exists. */
		closedir(dir);
		return ;
	} else if (ENOENT == errno) {
		/* Directory does not exist. */
		mkdir(path, 0700);
	} else {
		/* opendir() failed for some other reason. */
	}
}
