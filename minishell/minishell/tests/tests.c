#include "../libft/libft.h"
#include "../src/minishell.h"
#include <stdio.h>
//#include <copyfile.h>
 
void test_pipe_parse()
{
	t_list* pipe = pipe_parse("ls -l | sort | cat -e");
	t_list* p = pipe;
	//printf("p->content = '%s'\n", (char*)p->content);
	if (!ft_strequ(p->content, "ls -l"))
	{
		printf("p->content != ls -l\n");
		exit(1);
	}
	p = p->next;
	if (!ft_strequ(p->content, "sort"))
	{
		printf("p->content != sort\n");
		exit(1);
	}
	p = p->next;
	//printf("p->content = '%s'\n", (char*)p->content);
	if (!ft_strequ(p->content, "cat -e"))
	{
		printf("p->content != cat -e\n");
		exit(1);
	}
	p = p->next;
	if (p != NULL)
	{
		printf("p->next!=NULL\n");
		exit(1);
	}
	printf("pipe_parse: OK\n");

	//pipe_exec(pipe);
	pipe_free(&pipe);
}
//
//void test_pipe_exec()
//{
//	char str[] = "echo 1";
//	const char** splitted = (const char**) ft_split3(str, " \t");
//	debug_print_zt_array(splitted);
//	char const** pipes[1];
// pipes[0] = splitted;
// pipes[1] = NULL;
//	t_list* pipe = pipe_create(pipes);
//	pipe_exec(pipe);
//	pipe_free(&pipe);
//}

void history()
{
	if (h_has_previous())
	{
		printf("has previous\n");
		exit(1);
	}

	if (h_has_next())
	{
		printf("has next\n");
		exit(1);
	}

	//if (h_get_current() != NULL)
	//{
	//	printf("h_get_current() != NULL\n");
	//	exit(1);
	//}

	h_append(ft_strdup("1"));
	//if (!ft_strequ("1", h_get_current()))
	//{
	//	printf("1!=h_get_current()\n");
	//	exit(1);
	//}

	if (!h_has_previous())
	{
		printf("!has previous\n");
		exit(1);
	}

	if (h_has_next())
	{
		printf("has next\n");
		exit(1);
	}
	h_append(ft_strdup("2"));
	//if (!ft_strequ("2", h_get_current()))
	//{
	//	printf("2!=h_get_current() = '%s'\n", h_get_current());
	//	exit(1);
	//}
	if (!ft_strequ("2", h_get_previous()))
	{
		printf("2!=h_get_previous()\n");
		exit(1);
	}
	if (!ft_strequ("2", h_get_current()))
	{
		printf("2!=h_get_current2()\n");
		exit(1);
	}
	if (h_has_next())
	{
		printf("has next2\n");
		exit(1);
	}
	printf("history: OK\n");
}

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
void		ls()
{
	process_command("ls");
	//process_command("ls -la");
	//process_command("ls -la src");
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
void compare_and_free(const char* e, const char* a, const char* name)
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
	compare_and_free(expected_out, actual_out, ft_strjoin(name, "_out"));
	compare_and_free(expected_err, actual_err, ft_strjoin(name, "_err"));
}
void test_pipe2()
{
	//execl("/bin/ls", "-l", NULL);
	//return;
	int fd[2];
	pipe(fd);
	int r = fd[0];
	int w = fd[1];

	if (fork() == 0) {
		dup2(w, STDOUT_FILENO);
		close(r); // just for safety
		execl("/bin/ls", "-l", NULL);
	}

	dup2(r, STDIN_FILENO);
	close(w); // just for safety
	execl("/usr/bin/sort", "", NULL);
}

void redirect_and_exec(int to, int from, const char* cmd, int to_close)
{
	redirect(to, from);
	close_fd(to_close);
	exec_ve2(cmd);
}
void exec_write(const char* cmd, int r, int w)
{
	int pid = ft_fork();
	if (is_child(pid))
	{
		debug_set_pname(cmd);
		redirect_and_exec(w, STDOUT_FILENO, cmd, r);
	}
	debug_printf("waiting %s > %d to finish\n", cmd, w);
	wait_child(pid);
	debug_printf("%s finished\n", cmd);
	close_fd(w);
}

void exec_read(const char* cmd, int r, int w)
{
	int pid = ft_fork();
	if (is_child(pid))
	{
		debug_set_pname(cmd);
		redirect_and_exec(r, STDIN_FILENO, cmd, w);
	}
	debug_printf("waiting %s > %d to finish\n", cmd, w);
	wait_child(pid);
	debug_printf("%s finished\n", cmd);
	close_fd(r);
}

void test_pipe4()
{
	int r;
	int w;
	ft_pipe(&r, &w);
	int pid = ft_fork();
	if (!is_child(pid))
	{
		exec_read("/usr/bin/sort", r, w);
	}
	else
	{
		exec_write("/bin/ls", r, w);
	}

}

void test_pipe5()
{
	int pid = ft_fork();
	if (is_child(pid))
	{
		test_pipe4();
	}
	wait_child(pid);
}

void test_pipe6()
{
	int r, w;
	ft_pipe(&r, &w);
	exec_write("/bin/ls", r, w);
	exec_read("/usr/bin/sort", r, w);
}


void test_pipe7()
{
	//t_list* p = pipe_parse("/bin/ls|/usr/bin/sort|/bin/cat -e");
	pipe_exec("/bin/ls | /bin/cat -e | /usr/bin/sort");
}

void test_pipe8()
{
	pipe_exec("/bin/echo 1 2 3 | /usr/bin/wc");
}

//void test_replace_quotes()
//{
//	char* str = replace_quotes("   \"   \"   \"\"");
//	if (!ft_str_equals(str, "   #quoted_param_1#   #quoted_param_2#"))
//	{
//		printf("expected: %s actual: %s\n","   #quoted_param_1#   #quoted_param_2#",str);
//		exit(1);
//	}
//	char* str2 = replace_quotes_back("#quoted_param_2# #quoted_param_1# #quoted_param_2#");
//	if (!ft_str_equals(str2, "\"\" \"   \" \"\""))
//	{
//		printf("expected: %s actual: %s\n", "\"\" \"   \" \"\"",str2);
//		exit(1);
//	}
//}

void dic()
{
	t_list* dic = NULL;
	assert_true(dic_is_empty(dic));
	assert_int_equals(0, dic_get_count(dic));
	dic_free(&dic);
	assert_false(dic_contains_key(dic, ""));
	assert_false(dic_contains_key(dic, NULL));
	dic = dic_add(dic, "key2", "value2");

	 



	assert_int_equals(1, dic_get_count(dic));

	dic = dic_add(dic, "key1", "value1");


	//dic_free(&dic);
	//ft_exit(1);
	
	
	assert_int_equals(2, dic_get_count(dic));
	assert_true(dic_contains_key(dic, "key2"));

	assert_str_equals("value2", dic_get_value(dic, "key2"));
	dic_replace(dic, "key2", "value_2");
	assert_str_equals("value_2", dic_get_value(dic, "key2"));

	assert_true(dic_contains_key(dic, "key1"));
	assert_str_equals("value1", dic_get_value(dic, "key1"));
	dic_replace(dic, "key1", "value_1");
	assert_str_equals("value_1", dic_get_value(dic, "key1"));
	dic = dic_remove(dic, "key1");
	assert_int_equals(1, dic_get_count(dic));
	assert_false(dic_contains_key(dic, "key1"));
	assert_true(dic_contains_key(dic, "key2"));


	dic_free(&dic);
	assert_is_null(dic);
	assert_true(dic_is_empty(dic));
	assert_int_equals(0, dic_get_count(dic));


	dic = dic_add(dic, "%paired_quote%1", "setenv");
	dic = dic_add(dic, "%paired_quote%2", "sort");

	dic_free(&dic);
	dic = dic_add(dic, "%paired_quote%1", "dir  with  spaces");
	dic = dic_add(dic, "%paired_quote%2", "mkdir");
	assert_true(dic_contains_key(dic, "%paired_quote%2"));

	dic_free(&dic);
	printf("dic: OK\n");
	//ft_exit(1);
}


void test_lg()
{
	assert_int_equals(0, int_lg(1));
	assert_int_equals(1, int_lg(10));
	assert_int_equals(1, int_lg(19));
	assert_int_equals(2, int_lg(100));
	printf("int_lg: OK\n");
}



void test_pipe9()
{
	process_command("\"cd\"");
	//process_command("\"setenv\"");
	return;
	process_command("\"setenv\" | \"sort\"");
	process_command("\"setenv\" | \"sort\"");
	process_command("rmdir  \"dir  with  spaces\"; \t\"mkdir\" \"dir  with  spaces\"");
	process_command("ls | cat -e | sort");
	process_command("ls | sort");
	process_command("ls | cat -e");
	process_command("setenv | sort");
	process_command("echo \"No dollar character\" 1 > &2 | cat -e");
	process_command("cat <<src");
	process_command("cat <<src | rev");
	process_command(" cat < out.txt <<src | rev");
	process_command("cat <out.txt | rev");
	process_command("cat <<src <out.txt | rev");
	process_command("ls | cat -e");
	process_command("ls | sort | cat -e");
	process_command("rm -rf t; mkdir t ; cd t ; ls -a ; ls | cat | wc -c > fifi ; cat fifi");
	process_command("base64 /dev/urandom | head -c1000 | grep 42 | wc -l | sed -e 's/1/Yes/g' -e 's/0/No/g'");
	process_command("echo \"Testing redirections, \" > /tmp/test.txt; cat -e /tmp/test.txt");
	process_command("echo \"with multiple lines \" >> /tmp/test.txt; cat -e /tmp/test.txt");
	process_command("wc -c < /tmp/test.txt");

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
	set_out_file("debug_out4.txt", "w");
	set_level(1);
	debug_printf("%s\n", "started");
	signal(SIGINT, ft_default_sig_handler);
	env_from_array(envp);
	ft_putstr("\n\n\n----------------\n\n\n");
	test_lg();
	dic();


	//	test_pipe();
		test_pipe9();
	//test_pipe6();
	ft_exit(0);

	test(test_pipe_parse, "test_pipe_parse");
	history();
	//	test(history, "history");
		//return 0;
	test(ls, "ls");
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
	ft_exit(0);
}
