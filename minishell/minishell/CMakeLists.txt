 
# Include sub-projects.
add_subdirectory ("src")
add_subdirectory ("libft")
#link_directories ("libft")
#add_dependencies(minishell libft)
add_dependencies(minishell ft)

#target_link_libraries(ft libft.a)
#target_link_libraries(ft libft.a)
#target_link_libraries(libft debug libft.a) 
