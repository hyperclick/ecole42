#include "../libft/libft.h"
#include "../src/minishell.h"
#include <stdio.h>

void		pwd()
{

	//printf("This goes to screen\n");
	//printf("This goes to out.txt");
	// call the function we want to collect the stdout from
	process_command("pwd");
	//printf("This should go to screen too, but doesn't\n");
}

void		comment_ignored()
{

}
#define BUF_SIZE 1
BOOL	compare_buffers(FILE* a, int e_read, char e_buf[BUF_SIZE], char a_buf[BUF_SIZE])
{
	int a_read;
	if ((a_read = fread(a_buf, 1, BUF_SIZE, a)) != e_read)
	{
		return (FALSE);
	}
	e_buf[e_read] = 0;
	a_buf[a_read] = 0;
	if (!ft_strequ(e_buf, a_buf))
	{
		return (FALSE);
	}
	return (TRUE);
}

BOOL		compare_files(const char* expected_file_name, const char* actual_file_name)
{
	printf("read\n");
	FILE* e = fopen(expected_file_name, "r");
	if (e == NULL)
	{
		perror(expected_file_name);
		exit (1);
	}
	FILE* a = fopen(actual_file_name, "r");
	if (a == NULL)
	{
		perror(actual_file_name);
		exit (1);
	}
	char e_buf[BUF_SIZE];
	char a_buf[BUF_SIZE];
	int e_read;
	while ((e_read = fread(e_buf, 1, BUF_SIZE, e)) > 0)
	{
		if (!compare_buffers(a, e_read, e_buf, a_buf))
		{
			return (FALSE);
		}
	}
	return (compare_buffers(a, e_read, e_buf, a_buf));
}

void		test(void(*f)(), const char* name)
{
	const char* expected_file_name = ft_strjoin2(2, name, "_expected.txt");
	const char* actual_file_name = ft_strjoin2(2, name, "_actual.txt");
	FILE* file = freopen(actual_file_name, "w", stdout);
	f();
	freopen("/dev/tty", "a", stdout);
	printf("hello\n");
	//fclose(file);
	if (compare_files(expected_file_name, actual_file_name))
	{
		printf("%s: OK\n", name);
	}
	else
	{
		printf("%s: failed\n", name);
		exit(1);
	}
	free((char*)actual_file_name);
	free((char*)expected_file_name);
}

int main(int argc, char** argv, char** envp)
{
	set_out_file("debug_out.txt", "w");
	set_level(1);
	debug_printf("%s\n", "started");
	signal(SIGINT, ft_default_sig_handler);
	env_from_array(envp);
	ft_putstr("\n\n\n----------------\n\n\n");
	test(pwd, "pwd");
	return (0);
}
