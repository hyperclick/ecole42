
ADD_LIBRARY(lists STATIC
    lstadd.c
    lstdel.c
    lstdelone.c
    lst_count.c
    lst_find.c
    lst_free.c
    lst_free_item.c
    lst_get_last.c
    lst_insert.c
    lstiter.c
    lstmap.c
    lstnew.c
    lst_reduce.c
    lst_remove_sorted.c
    )

        
#target_link_libraries(lists cc)