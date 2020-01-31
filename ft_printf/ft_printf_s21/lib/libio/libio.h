
#ifndef LIBIO_H
# define LIBIO_H
# include <unistd.h>
# include <stdlib.h>


void			ft_e_putstr(const char *str);
void			ft_e_ft_putstr_and_free(char *str);
void			ft_putchar(int c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(long long n);
void			ft_putchar_fd(int c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(long long n, int fd);


void			close_fd(int fd);
void			redirect(int a, int b);
void			save_stdin(void);
void			restore_stdin(void);
void			restore_stdout(void);
void			save_stdout(void);

#endif