
ADD_LIBRARY(ftprintf STATIC
	ft_printf.c
	ft_printf2.c
	ft_printf_fill_args.c
)

target_link_libraries(ftprintf str)
target_link_libraries(ftprintf ftio)
target_link_libraries(ftprintf ztarray)
