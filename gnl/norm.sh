clear
make re
norminette -R CheckForbiddenSourceHeader *.h
norminette -R CheckForbiddenSourceHeader *.c
rm libft/libft.a
rm libft/*.o
rm .DS_Store 
