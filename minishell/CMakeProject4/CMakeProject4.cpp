// CMakeProject4.cpp : Defines the entry point for the application.
//

#include "CMakeProject4.h"

#include <io.h>
#include <direct.h> // _getcwd
#include <stdlib.h> // free, perror
#include <stdio.h>  // printf
#include <string.h> // strlen
#include <process.h> //execve

#define BOOL unsigned char

void	test_getcwd()
{
	//char	buffer[300];

	char* buffer;

	// Get the current working directory:
	if ((buffer = _getcwd(NULL, 0)) == NULL)
		perror("_getcwd error");
	else
	{
		printf("%s \nLength: %zu\n", buffer, strlen(buffer));
		free(buffer);
	}

}

void	test_chdir(const char* dir)
{

	if (_chdir(dir))
	{
		switch (errno)
		{
		case ENOENT:
			printf("Unable to locate the directory: %s\n", dir);
			break;
		case EINVAL:
			printf("Invalid buffer.\n");
			break;
		default:
			printf("Unknown error.\n");
		}
	}
	else
		system("dir");
}

BOOL	fso_exists(const char *path)
{
	return (access(path, 0) == 0);
}

void	test_access()
{
	//https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/access-waccess?view=vs-2019

	int r = access("C:\\git\\ecole44\\CMakeProject4\\CMakeLists.txt", 0);
	if (r == EACCES)
	{
		printf("/nno access/n");
	}
}

char*	get_cur_dir(char *dst)
{

	char* buffer;

	// Get the current working directory:
	if ((buffer = _getcwd(NULL, 0)) == NULL)
	{
		perror("_getcwd error");
		dst[0] = 0;
	}
	else
	{
		printf("%s \nLength: %zu\n", buffer, strlen(buffer));
		strcpy(dst, buffer);
		free(buffer);
	}
	return dst;
}

void	test_execve()
{
//https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/execve-wexecve?view=vs-2019

	char* my_env[] =     // Environment for exec?e
	{
	   "THIS=environment will be",
	   "PASSED=to new process by",
	   "the EXEC=functions",
	   NULL
	};

	char* args[] = {"C:\\git\\ecole44\\CMakeProject4\\out\\build\\x64-Debug\\CMakeCache.txt", NULL};

	int r = _execve("notepad", args, my_env);
	if (r == -1)
	{
		perror("execve");
	}
}

int main(int argc,  // Number of strings in array argv
	char* argv[],       // Array of command-line argument strings
	char** envp)
{
	// Display each environment variable.
	printf("\nEnvironment variables:\n");
	//while (*envp != NULL)
	//	printf("  %s\n", *(envp++));

	char cur_dir[300];
	char dst_dir[300];

	get_cur_dir(cur_dir);

	dst_dir[0] = 0;
	strcat(strcat(dst_dir, cur_dir), "\\..");
	if (!fso_exists(dst_dir))
	{
		printf("not exists/n");
	}
	test_chdir(dst_dir);

	test_execve();
	printf( "Hello CMake2");
	return 0;
}
