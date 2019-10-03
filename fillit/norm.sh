clear
make re
norminette -R CheckForbiddenSourceHeader *.h
norminette -R CheckForbiddenSourceHeader *.c
rm libft.a
rm -r *.o
rm .DS_Store 
