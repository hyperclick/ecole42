

ADD_LIBRARY(ftprintf STATIC
	ft_printf.c
	#ft_printf2.c
	list_to_string.c
	replace_args/parsers.c
	replace_args/ft_printf_fill_args.c
	types.c
	float/float.h
	float/float.c
	float/float_2.c
	float/float_3.c
	float/float_4.c
	float/float_5.c
	float/precision.c
	to_list/add_free_item.c
	to_list/parse_format/create_free_fmt.c
	to_list/parse_format/format_parser.c
	to_list/parse_format/try_extract_id.c
	to_list/parse_format/handle_format_parsed.c
	to_list/to_list.c
)

target_link_libraries(ftprintf mem str  dic  io ztarray lists)
