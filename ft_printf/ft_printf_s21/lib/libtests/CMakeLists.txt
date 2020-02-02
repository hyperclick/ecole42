
ADD_LIBRARY(tests STATIC
	asserts.c
	asserts2.c
	test_runner.c
)

target_link_libraries(tests str)
target_link_libraries(tests io)
target_link_libraries(tests ztarray)
target_link_libraries(tests ftprintf)
target_link_libraries(tests mem)