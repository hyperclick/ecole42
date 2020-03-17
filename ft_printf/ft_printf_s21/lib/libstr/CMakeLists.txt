
ADD_LIBRARY(str STATIC
ft_contains.c
ft_is_number.c
ft_isalnum.c
ft_isalpha.c
ft_isascii.c
ft_isdigit.c
ft_isprint.c
ft_itoa.c
prepend_and_free.c
ft_str_append.c
ft_str_count_chars.c
ft_str_ends_with.c
ft_str_equals.c
ft_str_insert_at.c
ft_str_is_empty.c
ft_str_left_from.c
ft_str_remove_at.c
ft_str_repeat.c
ft_str_remove_comment.c
ft_str_replace.c
ft_str_starts_with.c
ft_strcat.c
ft_strchr.c
ft_strclr.c
ft_strcmp.c
ft_strcpy.c
ft_strdel.c
ft_strdup.c
ft_strequ.c
ft_striter.c
ft_striteri.c
ft_strjoin.c
ft_strlcat.c
ft_strlen.c
ft_strmap.c
ft_strmapi.c
ft_strncat.c
ft_strncmp.c
ft_strncpy.c
ft_strndup.c
ft_strnequ.c
ft_strnew.c
ft_strnstr.c
ft_strrchr.c
ft_strrev.c
ft_strsplit.c
ft_strstr.c
ft_strsub.c
ft_strtrim.c
ft_tolower.c
ft_toupper.c
)


target_link_libraries(str mem)
