
.PHONY: clean fclean re make all

FILENAMES = errors.c ls.c cur_dir.c entry.c entry_utils.c entry_utils2.c get_folder_entries.c main.c path_utils.c parse_arguments.c print_entries.c print_folders.c sort.c
NAME = ft_ls

SRCS	=$(addprefix src/, $(FILENAMES))

OBJS			= $(SRCS:%.c=%.o)

CC		= gcc
CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -I includes/
LIBFT	= libft/libft.a

all: $(NAME)

$(OBJS): %.o: %.c 
	$(CC) $(CFLAGS) $< -o $@ -c 
	

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJS)


clean:
	@rm -rf $(OBJS)
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all

