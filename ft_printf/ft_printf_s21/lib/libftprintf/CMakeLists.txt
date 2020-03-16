

ADD_LIBRARY(ftprintf STATIC
	ft_printf.c
	list_to_string.c
	list_parse_and_format/process_format/parsers/char_to_string.c
	list_parse_and_format/process_format/parsers/pchar_to_string.c
	list_parse_and_format/process_format/parsers/hex_to_string.c
	list_parse_and_format/process_format/parsers/int_to_string.c
	list_parse_and_format/process_format/parsers/oct_to_string.c
	list_parse_and_format/process_format/parsers/parse_d.c
	list_parse_and_format/process_format/parsers/parse_u.c
	list_parse_and_format/process_format/process_format.c
	list_parse_and_format/process_format/process_sign.c
	list_parse_and_format/process_format/process_blank.c
	list_parse_and_format/process_format/process_width.c
	list_parse_and_format/process_format/process_precision.c
	list_parse_and_format/process_format/process_type.c
	list_parse_and_format/replace_args.c
	types.c
	#float/float.h
	#float/float.c
	#float/float_2.c
	#float/float_3.c
	#float/float_4.c
	#float/float_5.c
	#float/precision.c
	list_create/add_free_item.c
	list_create/parse_format/create_free_fmt.c
	list_create/parse_format/format_parser.c
	list_create/parse_format/try_extract_id.c
	list_create/parse_format/handle_format_parsed.c
	list_create/to_list.c
)

target_link_libraries(ftprintf mem str  dic  io ztarray lists)
