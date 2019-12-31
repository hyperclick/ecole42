
.PHONY: clean fclean re make all

FILENAMES = console_reader.c cmd_parser.c ft_set_env.c env.c exec.c folders.c history.c pipe_exec.c pipe_parse.c replace_quoted.c shell.c

NAME = minishell

SRCS	=$(addprefix src/, $(FILENAMES))

OBJS			= $(SRCS:%.c=%.o)

CC		= gcc
CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -g -I includes/

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
	#rm ut

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all

ut:	$(NAME)  tests/*.c 
	$(CC) tests/*.c $(OBJS) $(LIBFT) -g -o ut
