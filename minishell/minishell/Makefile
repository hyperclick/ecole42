
.PHONY: clean fclean re make all

FILENAMES = cmd_parser.c main.c 

NAME = minishell

SRCS	=$(addprefix src/, $(FILENAMES))

OBJS			= $(SRCS:%.c=%.o)

CC		= gcc
CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -I includes/

LIBFT = libft/libft.a

all:		$(NAME)

$(OBJS): %.o: %.c 
	$(CC) $(CFLAGS) $< -o $@ -c 
	
$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) 


clean:
	@rm -rf $(OBJS)
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all

