
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