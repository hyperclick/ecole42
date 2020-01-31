#ifndef LIBMEM_H
#define LIBMEM_H


# include <sys/ioctl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <termios.h>
# include <signal.h>

# define BOOL int
# define FALSE 0
# define TRUE 1
# define MAX(a, b) a > b ? a : b
# define MIN(a, b) a > b ? b : a
# define MAX_UNSIGNED_VALUE(T) (T)((T) - 1)
# define MAX_SIZE_T MAX_UNSIGNED_VALUE(size_t)



void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void *ft_memset(void *ptr, int value, size_t num);
void			ft_bzero(void *s, size_t n);
void *ft_memcpy(void *d, const void *s, size_t n);
void *ft_memccpy(void *d, const void *s, int c, size_t n);
void *ft_memmove(void *dst, const void *src, size_t len);
void *ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
#endif
