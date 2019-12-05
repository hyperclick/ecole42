
.PHONY: clean fclean re make all

FILENAMES = console_reader.c cmd_parser.c env.c folders.c exec.c shell.c

NAME = minishell

SRCS	=$(addprefix src/, $(FILENAMES))

OBJS			= $(SRCS:%.c=%.o)

CC		= gcc
CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -I includes/

LIBFT = libft/libft.a

all:		$(NAME) ut

$(OBJS): %.o: %.c 
	$(CC) $(CFLAGS) $< -o $@ -c 
	
$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) src/main.c  -o $(NAME) $(OBJS) $(LIBFT) 


clean:
	@rm -rf $(OBJS)
	@make clean -C libft
	rm ut

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all

ut:	$(NAME)  tests/*.c 
	$(CC) tests/*.c $(OBJS) $(LIBFT) -o ut