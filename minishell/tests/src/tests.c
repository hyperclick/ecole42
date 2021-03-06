#include "../../minishell/libft/libft.h"
#include "../../minishell/src/minishell.h"
#include <stdio.h>
//#include <copyfile.h>

void test_exec()
{
	process_command("src");
	process_command("foo");
	process_command("minishell");
	process_command("echo 1   2    \t3");

	process_command("");
	process_command("\t ");
}


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
	//pipe_exec(pipe);
	pipe_free(&pipe);
	printf("pipe_parse: OK\n");

}

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
	//	if (!ft_strequ("1", h_get_current()))
	//	{
	//		printf("1!=h_get_current()\n");
	//		exit(1);
	//	}

	if (!h_has_previous())
	{
		printf("1: !has previous\n");
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

	h_free();

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

	h_append(ft_strdup("1"));
	if (!h_has_previous())
	{
		printf("!has previous\n");
		exit(1);
	}
	if (!ft_strequ("1", h_get_previous()))
	{
		printf("1!=h_get_previous()\n");
		exit(1);
	}
	if (h_has_previous())
	{
		printf("2: has previous\n");
		exit(1);
	}


	printf("history: OK\n");
}

void		env()
{
	process_command("unsetenv w");
	process_command("setenv q w");
	process_command("echo $q");
	process_command("unsetenv q");
	process_command("echo $q");
}
void		ls()
{
	process_command("echo /bin/ls:;/bin/ls");
	process_command("echo \nls:;ls");
	process_command("rm -r \"not empty dir ls\"; mkdir \"not empty dir ls\"; mkdir \"not empty dir ls\"/dir1; touch \"not empty dir ls\"/file1");
	//process_command("ls -la");
	process_command("echo \nls ;ls \"not empty dir ls\"");
	//process_command("echo \n/bin/ls -aF:;/bin/ls    -aF");
	//process_command("echo \n/bin/ls -a -F:;/bin/ls -a \t-F");
}

void		cd_bad()
{
	process_command("cd -");
	process_command("cd \\");
}

void		cd_good_a()
{
	process_command(
		"pwd;	\
cd test_cases/actual;pwd; \
cd /;/bin/pwd;	\
echo cd ~;	\
cd ~;pwd;	\
echo cd -;	\
cd - ;		\
echo cd ~/git;	\
cd ~/git; pwd;	\
echo \"cd\"	\
\"cd\";pwd; \
echo cd ..;	\
cd ..; pwd; \
echo cd /////; \
cd /////; pwd; \
cd ..; pwd;	\
cd ..; pwd;	\
cd /bin; pwd;	\
		");

}


void		cd_good_e()
{
	system(
		"pwd;	\
cd test_cases/actual;pwd; \
cd /;/bin/pwd;	\
echo cd ~;	\
cd ~;pwd;	\
echo cd -;	\
cd - ;		\
echo cd ~/git;	\
cd ~/git; pwd;	\
echo \"cd\"	\
\"cd\";pwd; \
echo cd ..;	\
cd ..; pwd; \
echo cd /////; \
cd /////; pwd; \
cd ..; pwd;	\
cd ..; pwd;	\
cd /bin; pwd;	\
		");
}

void		two_commands_good()
{
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
void		echo_n_args()
{
	process_command("echo 1 2 3");
	process_command("echo it works");
}

void		echo_home()
{
	process_command("echo $HOME");
}

void		echo_quotes()
{
	process_command("echo \"q\"");
	process_command("echo \"it works\"");
}
void		pwd()
{
	process_command("pwd");
}
void		comment_ignored_a()
{
	process_command("#pwd");
	process_command("pwd #");
}
void		comment_ignored_e()
{
	system("#pwd");
	system("pwd #");
}
void		comment_ignored_bad()
{
	process_command("pwd#");
}

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
	debug_set_pname("test");
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
void		restore_curdir(const char *curdir)
{
	if (chdir(curdir) != 0)
	{
		perror("couldn't restore curdir\n");
		debug_printf("couldn't restore curdir\n");
		ft_exit(1);
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

void test_pipe_1()
{
	process_command("echo 123 |rev");
	process_command("echo 123 | cat -e |rev");
	process_command("echo 123456789 | head -c3");

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
	assert_true(dic_contains_key(dic, "key2"));

	dic = dic_remove(dic, "key2");
	assert_is_null(dic);
	assert_int_equals(0, dic_get_count(dic));
	assert_false(dic_contains_key(dic, "key2"));
	
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

void test_set_env_e()
{

	process_command("env");
	process_command("echo ; echo env finished");
	process_command("setenv q w");
	process_command("echo ; echo q = $q");
	process_command("env");
	process_command("unsetenv q");
	process_command("echo ; echo q = $q");
	process_command("env");

}

void test_set_env_a()
{
	//process_command("unsetenv q");
	process_command("\"setenv\"");
	process_command("echo ; echo env finished");
	process_command("setenv q w");
	process_command("echo ; echo q = $q");
	process_command("env");
	process_command("unsetenv q");
	process_command("echo ; echo q = $q");
	process_command("env");

}

void	path_is_used()
{
	//process_command("echo path = $PATH");
	process_command("unsetenv PATH");
	process_command("echo path = $PATH");
	process_command("setenv PATH /bin:/usr/bin");
	process_command("echo path = $PATH");
}

void quotes()
{
	//process_command("rmdir  \"dir  with  spaces\"; \t\"mkdir\" \"dir  with  spaces\" ; ls");
	process_command("rmdir  \"dir  with  spaces\"; \t\"mkdir\" \"dir  with  spaces\" ; ls \"dir  with  spaces\"");

	process_command("rm -r \"not empty dir\";mkdir \"not empty dir\"; mkdir \"not empty dir\"/\"dir\tone\"; ls \"not empty dir\"/\"dir\tone\"");
	//	process_command("rmdir  \"dir  with  spaces\"; \t\"mkdir\" \"dir  with  spaces\" ; cd \"dir  with  spaces\"; pwd");
}

void test_pipe9()
{
	process_command("\"setenv\" | \"sort\"");
	process_command("\"setenv\" | \"sort\"");
	process_command("echo \nls -laF; ls -laF| sort");
	process_command("echo \nls ;ls | cat -e");
	process_command("echo \nls ;ls | sort | cat -e");
	process_command("echo \nls -l -a -F; ls -l -a -F| cat -e | sort");

	process_command("setenv | sort");
	process_command("base64 /dev/urandom | head -c100 | grep 42 | wc -l | sed -e \"s/1/Yes/g\" -e \"s/0/No/g\"");
	return ;
	process_command("echo \"No dollar character\" 1 > &2 | cat -e");
	process_command("cat <<src");
	process_command("cat <<src | rev");
	process_command(" cat < out.txt <<src | rev");
	process_command("cat <out.txt | rev");
	process_command("cat <<src <out.txt | rev");
	process_command("rm -rf t; mkdir t ; cd t ; ls -a ; ls | cat | wc -c > fifi ; cat fifi");
	process_command("echo \"Testing redirections, \" > /tmp/test.txt; cat -e /tmp/test.txt");
	process_command("echo \"with multiple lines \" >> /tmp/test.txt; cat -e /tmp/test.txt");
	process_command("wc -c < /tmp/test.txt");
}

void		fe(const char* argv[])
{
	pid_t pid;
	pid = ft_fork();
	if (is_child(pid))
	{
		debug_set_pname(argv[0]);
		exec_ve(argv);
		debug_printf("!!!should not be here!!!\n");
	}

	debug_printf("%s launched\n", argv[0]);
	//wait_child(pid);
}
void pwd2()
{
	pipe_exec(ft_strdup("pwd"));
	return ;
	pid_t pid;
	char** args = ft_split3("/bin/pwd", "|");


	fe((const char **)args);
	return ;
	pid = ft_fork();
	if (is_child(pid))
	{
		debug_set_pname(args[0]);
		exec_ve((const char **)args);
		debug_printf("!!!should not be here!!!\n");
	}
	ft_free_null_term_array((void**)args);
	wait_child(pid);
	return ;

	
}

char g_str[] = "123";
void	test_printf_e()
{
	//printf("ptr: %p\n", g_str);
	printf("number: %d, char: %c, string: '%s'\n", 1, 'a', "abc");
	printf(": %d\n", 1);
	printf("%s%s\n", "str1_", "str2");
	
	printf("1\n");
	printf("%s\n", "str");
	//printf(NULL);
}
void	test_printf_a()
{
	//ft_printf("ptr: %p\n", g_str);
	ft_printf("number: %d, char: %c, string: '%s'\n", 1, 'a', "abc");
	ft_printf(": %d\n", 1);
	ft_printf("%s%s\n", "str1_", "str2");
	
	assert_int_equals(0, count_tokens("%"));
	assert_int_equals(0, count_tokens(""));
	assert_int_equals(0, count_tokens("%%"));
	assert_int_equals(1, count_tokens("%%1"));
	assert_int_equals(1, count_tokens("%1"));
	assert_int_equals(2, count_tokens("%%1%2"));
	assert_int_equals(0, count_tokens("% "));
	ft_printf("1\n");
	ft_printf("%s\n", "str");
	
	//ft_printf(NULL);
}

void	test_debug_printf(const char* format, ...)
{
	int f = open("printf_out.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IWRITE);
	va_list argptr;
	va_start(argptr, format);
	ft_vprintf_fd(f, format, argptr);
	va_end(argptr);
//	fflush(output_stream);
	close(f);
}

void	test_check_exit()
{
	assert_false(has_exit("exit1"));
	assert_false(has_exit("cd exit"));
	assert_true(has_exit(" exit\t"));
	//assert_true(has_exit("\"exit\""));
	assert_true(has_exit(" exit > 1"));
	assert_true(has_exit("exit<1"));
	assert_true(has_exit("exit<<1"));
}

int main(int argc, char** argv, char** envp)
{
	init(argc, argv, envp);
	test_check_exit();
	
	
	//process_command("/bin/ls");
//ft_exit(0);
	//process_command(" echo 1 | sed -e 's/1/Yes/g'");
	//debug_print_zt_array((const char**)env_to_array());

	//system("env");
	//process_command("echo 1");

	//process_command("ls | sort");
		//ft_exit(0);
	//	process_command("base64 /dev/urandom | head -c100");
	//	ft_exit(0);
	//process_command("base64 /dev/urandom | head -c1000 | grep 42 | wc -l | sed -e 's/1/Yes/g' -e 's/0/No/g'");


		//test_pipe_1();

	//test(pwd2, "pwd2");
	test_pipe9();
	test2(test_printf_e, test_printf_a, "printf");
	test(path_is_used, "path_is_used");
	test(test_exec, "test_exec");

	test(test_pipe_1, "test_pipe_1");
	test(quotes, "quotes");
	//ft_exit(0);
	test_lg();
	dic();
	history();
	test(cd_bad, "cd_bad");
	test_pipe_parse();
	test(two_commands_bad, "two_commands_bad");

	test(echo_quotes, "echo_quotes");



	test(env, "env");
	test(ls, "ls");

	char* restore_home = ft_strjoin("setenv HOME ", env_get_value("HOME"));
	process_command("setenv HOME fake_home_for_tests");
	test(echo_tilde, "echo_tilde");
	test(echo_home, "echo_home");
	process_command(restore_home);
	free(restore_home);

	test(echo_n_args, "echo_n_args");
	//test(pwd, "pwd");
	test2(comment_ignored_e, comment_ignored_a, "comment_ignored");
	test(comment_ignored_bad, "comment_ignored_bad");
	test(two_commands_good, "two_commands_good");
	test2(cd_good_e, cd_good_a, "cd_good");
	//test(test_pipe_parse, "test_pipe_parse");
	//	test(history, "history");
		//return 0;
	//return 0;



	char* restore_ld_preload = ft_strjoin("setenv LD_PRELOAD ", env_get_value("LD_PRELOAD"));
	process_command("setenv LD_PRELOAD \"\"");
	test2(test_set_env_e, test_set_env_a, "set_env");
	if (restore_ld_preload != NULL)
	{
		printf("restore_ld_preload = %s\n", restore_ld_preload);

		process_command(restore_ld_preload);
		debug_set_pname("tests");
		free(restore_ld_preload);
	}

	printf("all tests passed\n");

	process_command("exit");
	return (1);
}
