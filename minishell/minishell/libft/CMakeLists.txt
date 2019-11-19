# CMakeList.txt : CMake project for CMakeProject1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
file(GLOB src *.c)
# Add source to this project's executable. 
add_library ("ft" STATIC libft.h ${src})
#add_library ("libft" STATIC  ft_putstr.c)

#target_link_libraries(ft libft.a)
#target_link_libraries(libft debug libft.a) 

# TODO: Add tests and install targets if needed.
 