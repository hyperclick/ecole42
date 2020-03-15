

ADD_LIBRARY(ftprintf STATIC
	ft_printf.c
	list_to_string.c
	replace_args/parsers.c
	replace_args/replace_args.c
	replace_args/process_format/process_format.c
	replace_args/process_format/process_sign.c
	replace_args/process_format/process_blank.c
	replace_args/process_format/process_width.c
	replace_args/process_format/process_precision.c
	replace_args/process_format/process_type.c
	types.c
	#float/float.h
	#float/float.c
	#float/float_2.c
	#float/float_3.c
	#float/float_4.c
	#float/float_5.c
	#float/precision.c
	to_list/add_free_item.c
	to_list/parse_format/create_free_fmt.c
	to_list/parse_format/format_parser.c
	to_list/parse_format/try_extract_id.c
	to_list/parse_format/handle_format_parsed.c
	to_list/to_list.c
)

target_link_libraries(ftprintf mem str  dic  io ztarray lists)
