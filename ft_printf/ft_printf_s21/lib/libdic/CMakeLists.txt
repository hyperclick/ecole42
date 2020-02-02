
ADD_LIBRARY(dic STATIC
	dic.c
	dic2.c
	dic3.c
	dic4.c
)

target_link_libraries(dic lists)
target_link_libraries(dic str)
target_link_libraries(dic io)