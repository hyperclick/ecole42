
.PHONY: clean fclean re make all

FILENAMES = test_runner.c

NAME = tests

SRCS	=$(addprefix src/, $(FILENAMES))

H		= src/test_runner.h src/tests.h

OBJS			= $(SRCS:%.c=%.o)

CC		= gcc
CFLAGS	+= -Wall -Wextra -Werror  -g

LIBFT = ../ft_select_s21/libft/libft.a

all:		$(NAME)

$(OBJS): %.o: %.c 
	$(CC) $(CFLAGS) $< -o $@ -c 

ft_select:
	make -C ../ft_select_s21

#$(NAME): ft_select $(OBJS)

$(NAME): ft_select $(OBJS) $(H) 
	$(CC) $(CFLAGS) src/tests.c  -o $(NAME) $(OBJS) ../ft_select_s21/src/*.o ../ft_select_s21/libft/libft.a -ltermcap

clean:
	rm -rf $(OBJS)
	make clean -C ../ft_select_s21
	rm -f $(NAME)

fclean: clean
	make fclean -C ../ft_select_s21 
	rm -rf $(NAME)

re: fclean all
