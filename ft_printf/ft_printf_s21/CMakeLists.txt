
project ("ft_printf")

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(GCC_COVERAGE_LINK_FLAGS    "-Wall -Wextra -Werror")

set(LIBMEM_DIR "lib/libmem")
include_directories(${LIBMEM_DIR})
add_subdirectory(${LIBMEM_DIR})

set(LIBZTARRAY_DIR "lib/libztarray")
include_directories(${LIBZTARRAY_DIR})
add_subdirectory(${LIBZTARRAY_DIR})

set(LIBIO_DIR "lib/libio")
include_directories(${LIBIO_DIR})
add_subdirectory(${LIBIO_DIR})

set(LIBSTR_DIR "lib/libstr")
include_directories(${LIBSTR_DIR})
add_subdirectory(${LIBSTR_DIR})

set(LIBLISTS_DIR "lib/liblists")
include_directories(${LIBLISTS_DIR})
add_subdirectory(${LIBLISTS_DIR})

set(LIBDIC_DIR "lib/libdic")
include_directories(${LIBDIC_DIR})
add_subdirectory(${LIBDIC_DIR})

set(LIBFTPRINTF_DIR "lib/libftprintf")
include_directories(${LIBFTPRINTF_DIR})
add_subdirectory(${LIBFTPRINTF_DIR})

add_subdirectory ("src")

set(LIBTESTS_DIR "lib/libtests")
include_directories(${LIBTESTS_DIR})
add_subdirectory(${LIBTESTS_DIR})