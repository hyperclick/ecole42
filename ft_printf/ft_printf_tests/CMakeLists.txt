project(ft_printf_tests C)

OPTION(DEFINE_MACRO "Option description" ON)
#ADD_DEFINITIONS(-DMYLIB_FOUND)

set(CMAKE_C_STANDARD 99)


add_executable(${PROJECT_NAME} tests.c)


target_link_libraries(${PROJECT_NAME} ftprintf)
include_directories (../ft_printf_s21/lib/libftprintf)


target_link_libraries(${PROJECT_NAME} tests)
include_directories (../ft_printf_s21/lib/libtests)

target_link_libraries(${PROJECT_NAME} mem)
include_directories (../ft_printf_s21/lib/libmem)

target_link_libraries(${PROJECT_NAME} mem)
include_directories (../ft_printf_s21/lib/libstr)