

//BOOL	compare_buffers(int e_read, int a_read, char e_buf[BUF_SIZE], char a_buf[BUF_SIZE]);
//BOOL		compare_files(const char* expected_file_name, const char* actual_file_name);
//BOOL	compare_and_free(const char* e, const char* a, const char* name);
//void	redirect_and_exec(void(*f)(), const char* out_file_name, const char* err_file_name);
//void		restore_curdir(const char* curdir);

void		test2(void(*e)(), void(*a)(), const char* name);

void		test(void(*f)(), const char* name);