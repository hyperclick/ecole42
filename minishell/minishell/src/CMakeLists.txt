# CMakeList.txt : CMake project for CMakeProject1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# TODO: Add tests and install targets if needed.

include_directories(${CMAKE_SOURCE_DIR}/minishell/libft)
#include_directories(${CMAKE_SOURCE_DIR}/sharedmod)

#link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

file(GLOB src *.c)
# Add source to this project's executable.
add_executable (minishell ${src})
#target_link_libraries(ft debug libft.a)
#target_link_libraries(libft debug libft.a)
#target_link_libraries(ft debug libft/libft.a)


target_link_libraries(minishell debug ft)
#target_link_libraries(minishell debug libft.a)
#target_link_libraries(theapp debug sharedmod.lib)
#target_link_libraries(theapp optimized sharedmod.lib)