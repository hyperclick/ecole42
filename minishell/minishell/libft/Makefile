
NAME		= libft.a
CFLAGS		= -g -Wall -Werror -Wextra -I. -c
FILES		= asserts.c debug.c debug2.c log.c dic.c dic2.c dic3.c dic4.c int_lg.c ft_exec.c ft_file.c ft_free_zt_array.c ft_str_insert_at.c ft_str_count_chars.c ft_str_replace.c ft_str_remove_comment.c ft_str_left_from.c ft_lst_insert.c ft_lst_count.c ft_lst_find.c ft_lst_free.c ft_lst_free_item.c ft_lst_reduce.c ft_e_putstr.c ft_str_starts_with.c ft_str_is_empty.c ft_str_equals.c ft_readline.c ft_sort_strings.c ft_ends_with.c ft_printf.c ft_printf2.c ft_starts_with.c ft_last_index.c ft_memcmp.c ft_striteri.c ft_memcpy.c ft_strjoin.c ft_memdel.c ft_strlcat.c ft_atoi.c ft_memmove.c ft_strlen.c ft_bzero.c ft_memset.c ft_strmap.c ft_contains.c ft_putchar.c ft_strmapi.c ft_count_words.c ft_putchar_fd.c ft_strncat.c ft_is_number.c ft_putendl.c ft_strncmp.c ft_isalnum.c ft_putendl_fd.c ft_strncpy.c ft_isalpha.c ft_putnbr.c ft_strndup.c ft_isascii.c ft_putnbr_fd.c ft_strnequ.c ft_isdigit.c ft_putstr.c ft_strnew.c ft_isprint.c ft_putstr_fd.c ft_strnstr.c ft_itoa.c ft_split.c ft_strrchr.c ft_strsplit.c ft_lstadd.c ft_strcat.c ft_strstr.c ft_lstdel.c ft_strchr.c ft_strsub.c ft_lstdelone.c ft_strclr.c ft_strtrim.c  ft_lstiter.c ft_strcmp.c ft_tolower.c ft_lstmap.c ft_strcpy.c ft_toupper.c ft_lstnew.c ft_strdel.c ft_memalloc.c ft_strdup.c  ft_memccpy.c ft_strequ.c ft_memchr.c ft_striter.c ft_sqrt_up.c ft_str_append.c ft_str_remove_at.c save_file_no.c

OBJ			= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
