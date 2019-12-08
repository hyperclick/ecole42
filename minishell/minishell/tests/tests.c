#include "../libft/libft.h"
#include "../src/minishell.h"
#include <stdio.h>
//#include <copyfile.h>

void		env()
{
	process_command("setenv q w"); 
	process_command("echo $q");
	process_command("unsetenv q");
	process_command("echo $q");
	//process_command("set q=w");
	//printf("q = '%s'\n", env_get_value("q"));
	//process_command("set q =q");
	//printf("q = '%s'\n", env_get_value("q"));
	//process_command("set q = e");
	//printf("q = '%s'\n", env_get_value("q"));
}

void		cd_bad()
{
	process_command("cd -");
	process_command("cd \\");
}
void		cd_good()
{
	process_command("pwd");
	process_command("cd ~;pwd");
	process_command("cd -");
	//process_command("pwd");
	//process_command("cd ..");
	//process_command("cd /////; pwd");
	//process_command("cd -");
	//process_command("cd; pwd");
	//process_command("cd -");
	//process_command("cd /////; pwd");
	//process_command("cd ..; pwd");
	//process_command("cd ..;pwd;");
}

void		two_commands_good()
{
	process_command("pwd;");
	process_command("echo echo1;;echo echo2");
	process_command("echo echo3;#;echo echo4");
	process_command("echo echo5;echo echo6");
	process_command("echo echo7;echo echo8");
}

void		two_commands_bad()
{
	process_command(";");
	process_command(";;");
	process_command(";;;");
	process_command("; ;");
}

void		echo_tilde()
{
	process_command("echo ~");
}
void		echo_home()
{
	process_command("echo $HOME");
}

void		echo_quotes()
{
	process_command("echo \"q\"");
}
void		pwd()
{
	process_command("pwd");
}
void		comment_ignored()
{
	process_command("#pwd");
	process_command("pwd #");
	process_command("pwd#");
}

#define BUF_SIZE 10
BOOL	compare_buffers(int e_read, int a_read, char e_buf[BUF_SIZE], char a_buf[BUF_SIZE])
{
	if (a_read != e_read)
	{
		printf("a_read: %d, e_read: %d\n", a_read, e_read);
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
		exit (1);
	}
	FILE* e = fopen(expected_file_name, "r");
	if (e == NULL)
	{
		perror(expected_file_name);
		exit (1);
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
	BOOL r= (compare_buffers(e_read, fread(a_buf, 1, BUF_SIZE, a), e_buf, a_buf));
	fclose(a);
	fclose(e);
	return (r);
}
void compare_and_free(const char* e, const char *a, const char* name)
{
	if (compare_files(e, a))
	{
		printf("%s: OK\n", name);
	}
	else
	{
		printf("%s: failed\n", name);
		exit(1);
	}
	free((char*)e);
	free((char*)a);
	free((char*)name);
}

void		test(void(*f)(), const char* name)
{
	debug_printf("");
	debug_printf("testing %s\n", name);
	const char* expected_out = ft_strjoin2(3, "test_cases/expected/", name, "_out.txt");
	const char* actual_out = ft_strjoin2(3, "test_cases/actual/", name, "_out.txt");
	const char* expected_err = ft_strjoin2(3, "test_cases/expected/", name, "_err.txt");
	const char* actual_err = ft_strjoin2(3, "test_cases/actual/", name, "_err.txt");
	FILE* f_out = freopen(actual_out, "w", stdout);
	FILE* f_err = freopen(actual_err, "w", stderr);
	f();
	//fflush(file);
	//fflush(stdout);
	//fclose(stdout);
	//char* cmd = ft_strjoin2(4, "cp ", actual_out, " ", ft_strjoin(actual_out, ".copy.txt"));
	//printf("system(%s)\n", cmd);
	//printf("press enter...\n");
	//char ch[10];
	//read(STDIN_FILENO, ch, 10);
	//system(cmd);
	//process_command(cmd);
	//free(cmd);
	freopen("/dev/tty", "a", stdout);
	freopen("/dev/tty", "a", stderr);
	//fseek(f_out, 0, 0);
	//int r = fread(ch,1, 9, f_out);
	//ch[9] = 0;
	//printf("'%s' r = %d\n", ch, r);
	//fclose(f_out);
	compare_and_free(expected_out, actual_out, ft_strjoin(name,"_out"));
	compare_and_free(expected_err, actual_err, ft_strjoin(name,"_err"));
}

int main(int argc, char** argv, char** envp)
{
////	char name[] = "test_cases/actual/cd_good_out - cannot open.txt";
//	char name[] = "test_cases/actual/cd_good_out.txt";
//	FILE* a = fopen(name, "r");
//	if (a == NULL)
//	{
//		perror(name);
//		exit(1);
//	}
//	printf("ok\n");
	//process_command("pwd");
//return 0;
	set_out_file("debug_out.txt", "w");
	set_level(1);
	debug_printf("%s\n", "started");
	signal(SIGINT, ft_default_sig_handler);
	env_from_array(envp);
	ft_putstr("\n\n\n----------------\n\n\n");

	//return 0;
	test(cd_bad, "cd_bad");
	test(cd_good, "cd_good");
	test(pwd, "pwd");
	test(comment_ignored, "comment_ignored");
	test(echo_tilde, "echo_tilde");
	test(echo_home, "echo_home");
	//return 0;
	test(env, "env");
	test(two_commands_bad, "two_commands_bad");
	test(two_commands_good, "two_commands_good");
	test(echo_quotes, "echo_quotes");
	//return (0);
}
