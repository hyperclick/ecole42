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
	//pipe_exec(pipe);
	pipe_free(&pipe);
	printf("pipe_parse: OK\n");

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


void pe2(char* cmd, int r, int w, int to_close, t_list* p)
{
	//int pid = ft_fork();
	//if (is_child(pid))
	//{
	//debug_set_pname(cmd);
	restore_stdin();
	restore_stdout();
	redirect(r, STDIN_FILENO);
	redirect(w, STDOUT_FILENO);
	///close_fd(to_close);
	///pipe_free(&p);
	(void)p;
	//exec_ve2(cmd);
	exec(cmd);
	//}
	//debug_printf("waiting %d > %s > %d to finish\n", r, cmd, w);
	//wait_child(pid);
	//debug_printf("%s finished\n", cmd);
	//free(cmd);
	if (w != STDOUT_FILENO)
	{
		close_fd(w);
	}
}

void pipe_exec2(t_list* p, int prev_r)
{
	if (p->next == NULL)
	{
		pe2(ft_strdup((char*)p->content), prev_r, STDOUT_FILENO, -1, p);
		return;
	}
	int r, w;
	ft_pipe(&r, &w);
	pe2(ft_strdup((char*)p->content), prev_r, w, r, p);
	pipe_exec2(p->next, r);
	debug_printf("pipe_exec finished\n");
}

void test_pipe_exec(char* str)
{
	t_list* p;
	p = pipe_parse(str);
	//free(str);
	pipe_exec2(p, STDIN_FILENO);
	pipe_free(&p);
	restore_stdin();
	restore_stdout();
}
void test_pipe_1()
{

	test_pipe_exec("cd ~|pwd");
	test_pipe_exec("cd -");
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

void test_set_env()
{
	process_command("\"setenv\"");

}

void test_pipe9()
{
	process_command("\"cd\"");
	process_command("\"setenv\" | \"sort\"");
	process_command("\"setenv\" | \"sort\"");
	process_command("rmdir  \"dir  with  spaces\"; \t\"mkdir\" \"dir  with  spaces\"");
	process_command("ls | cat -e | sort");
	process_command("ls | sort");
	process_command("ls | cat -e");
	process_command("setenv | sort");
	return;
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
	/*
	set_out_file("debug_out4.txt", "w");
	set_level(1);
	debug_printf("%s\n", "started");
	signal(SIGINT, ft_default_sig_handler);
	env_from_array(envp);
	ft_putstr("\n\n\n----------------\n\n\n");
	*/
	init(argc, argv, envp);

	process_command("pwd");
	ft_exit(0);
	test_pipe_1();
	ft_exit(0);

	//close_fd(STDOUT_FILENO);
	//ft_putstr("closed\n");

	int r, w;
	ft_pipe(&r, &w);
	redirect(STDOUT_FILENO, w);
	close_fd(r);



	process_command("cd ~| cd -");
	ft_exit(0);


	test(ls, "ls");

	test_lg();
	dic();
	test(test_set_env, "set_env");
//		test_pipe9();
	test_pipe_parse();
	//test(test_pipe_parse, "test_pipe_parse");
	history();
	//	test(history, "history");
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
	ft_exit(0);
}
