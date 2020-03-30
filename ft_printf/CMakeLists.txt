cmake_minimum_required(VERSION 3.10)

project(ft_printf_root)

ADD_DEFINITIONS(-DMAC_OS)

set(CMAKE_BUILD_TYPE Debug)
# Include sub-projects.
add_subdirectory ("ft_printf_s21")
add_subdirectory ("ft_printf_tests")
