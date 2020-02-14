

ADD_LIBRARY(ftprintf STATIC
	format_list.c
	format_parser.c 
	ft_printf.c
	ft_printf2.c
	ft_printf_fill_args.c
	parsers.c
	types.c
)

target_link_libraries(ftprintf mem str  dic  io ztarray lists)
