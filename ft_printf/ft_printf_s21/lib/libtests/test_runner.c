#include <stdio.h>
#include "libmem.h"
#include "libio.h"
#include "libstr.h"

#define BUF_SIZE 10

BOOL	compare_buffers(int e_read, int a_read, char e_buf[BUF_SIZE], char a_buf[BUF_SIZE])
{
	if (a_read != e_read)
	{
		printf("e_read: %d, a_read: %d\n", e_read, a_read);
		printf("not eq: e: '%s'(%d) a: '%s'(%d)\n", e_buf, e_read, a_buf, a_read);
		return (FALSE);
	}
	e_buf[e_read] = 0;
	a_buf[a_read] = 0;
	//printf("e: '%s'(%d) a: '%s'(%d)\n", e_buf, e_read, a_buf, a_read);
	if (!ft_strequ(e_buf, a_buf))
	{
		printf("not eq: e: '%s'(%d) a: '%s'(%d)\n", e_buf, e_read, a_buf, a_read);
		return (FALSE);
	}
	return (TRUE);
}

BOOL		compare_files(const char* expected_file_name, const char* actual_file_name)
{
	//printf("e: %s \na: %s \n", expected_file_name, actual_file_name);
	FILE* a = fopen(actual_file_name, "r");
	if (a == NULL)
	{
		perror(actual_file_name);
		exit(1);
	}
	FILE* e = fopen(expected_file_name, "r");
	if (e == NULL)
	{
		perror(expected_file_name);
		exit(1);
	}
	//printf("e: %s (%p)\na: %s (%p)\n", expected_file_name, e, actual_file_name, a);
	char e_buf[BUF_SIZE];
	char a_buf[BUF_SIZE];
	int e_read;
	while ((e_read = fread(e_buf, 1, BUF_SIZE - 1, e)) > 0)
	{
		int a_read = fread(a_buf, 1, BUF_SIZE - 1, a);
		//e_buf[e_read] = 0;
		//a_buf[a_read] = 0;
		//printf("e: '%s'(%d) a: '%s'(%d)\n", e_buf, e_read, a_buf, a_read);
		//exit(1);
		if (!compare_buffers(e_read, a_read, e_buf, a_buf))
		{
			fclose(a);
			fclose(e);
			return (FALSE);
		}
	}
	BOOL r = (compare_buffers(e_read, fread(a_buf, 1, BUF_SIZE, a), e_buf, a_buf));
	fclose(a);
	fclose(e);
	return (r);
}
BOOL	compare_and_free(const char* e, const char* a, const char* name)
{
	BOOL	ok = compare_files(e, a);
	if (ok)
	{
		printf("%s: OK\n", name);
	}
	else
	{
		printf("%s: failed\n", name);
		printf("e: %s\n", e);
		printf("a: %s\n", a);
	}
	free((char*)e);
	free((char*)a);
	free((char*)name);
	return (ok);
}

void	redirect_and_exec(void(*f)(), const char* out_file_name, const char* err_file_name)
{

	/*int out =*/ dup(STDOUT_FILENO);
	/*FILE* f_out =*/ freopen(out_file_name, "w", stdout);
	/*FILE* f_err =*/ freopen(err_file_name, "w", stderr);
	save_stdin();
	save_stdout();
	f();
	//debug_set_pname("test");
	//debug_printf("%s finished\n", name);
	//fflush(file);
	fflush(stdout);
	fclose(stdout);
	//fclose(f_out);
	//debug_printf("restore stdout\n");
	//redirect(out, STDOUT_FILENO);
	//restore_stdin();
	//restore_stdout();
	close_fd(STDOUT_FILENO);
	freopen("/dev/tty", "a", stdout);
	freopen("/dev/tty", "a", stderr);
	//for subsequent call process_command
	save_stdin();
	save_stdout();
}
void		restore_curdir(const char* curdir)
{
	if (chdir(curdir) != 0)
	{
		perror("couldn't restore curdir\n");
		printf("couldn't restore curdir\n");
		exit(1);
	}
}

void		test2(void(*e)(), void(*a)(), const char* name)
{
	const char* expected_out = ft_strjoin2(3, "test_cases/expected/", name, "_out.txt");
	const char* actual_out = ft_strjoin2(3, "test_cases/actual/", name, "_out.txt");
	const char* expected_err = ft_strjoin2(3, "test_cases/expected/", name, "_err.txt");
	const char* actual_err = ft_strjoin2(3, "test_cases/actual/", name, "_err.txt");

	char		curdir[PATH_MAX];
	debug_printf("curdir = %s\n", getcwd(curdir, PATH_MAX));

	debug_set_pname("test");
	debug_printf("testing %s\n", name);
	if (e != NULL)
	{
		redirect_and_exec(e, expected_out, expected_err);
		restore_curdir(curdir);
	}
	redirect_and_exec(a, actual_out, actual_err);
	restore_curdir(curdir);

	BOOL ok;
	ok = compare_and_free(expected_out, actual_out, ft_strjoin(name, "_out"));
	ok = compare_and_free(expected_err, actual_err, ft_strjoin(name, "_err")) && ok;
	if (!ok)
	{
		ft_exit(2);
	}
}


void		test(void(*f)(), const char* name)
{
	test2(NULL, f, name);
}