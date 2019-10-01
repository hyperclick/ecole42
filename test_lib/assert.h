#ifndef	BOOL
#define BOOL unsigned char
#endif
void	assert_pvoid(const void* expected, const void* actual);
void	assert_str(const char* expected, const char* actual);
void	assert_bytes(const unsigned char* expected, const unsigned char* actual, const size_t len);
void	assert_int(const int expected, const int actual);
void	assert_true(BOOL expected, BOOL actual);
