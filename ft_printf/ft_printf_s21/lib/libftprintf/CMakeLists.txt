
ADD_LIBRARY(ftprintf STATIC
	format_list.c
	ft_printf.c
	ft_printf2.c
	ft_printf_fill_args.c
)

target_link_libraries(ftprintf str)
target_link_libraries(ftprintf dic)
target_link_libraries(ftprintf io)
target_link_libraries(ftprintf ztarray)
target_link_libraries(ftprintf lists)
