#include "ls.h"


BOOL is_null_entry(t_entry e)
{
    return (e.is_null);
}

t_entry create_null_entry()
{
    t_entry e;
    e.is_null = TRUE;
    return (e);
}

t_f_n    get_full_name(const char name[])
{
    t_f_n   fn;
    int     pos;
    //todo: check overflow
    strcpy(fn.path, name);
    pos = ft_last_index(name, PATH_SEPARATOR);
   if (-1 == pos)
   {
       pos = 0;
   }
   int len = strlen(name);
   char *sub = ft_strsub(name, 0, pos);
   if (sub != NULL)
   {
        strcpy(fn.folder, sub);
        free(sub);
   }
   sub = ft_strsub(name, pos, len - pos);
   if (sub != NULL)
   {
        strcpy(fn.name, sub);
        free(sub);
   }
    return (fn);
}
void    fill_entry_dir(t_entry *e, struct stat s, const char name[])
{
    e->is_folder = TRUE;
    e->full_name = get_full_name(name);
    e->is_null = FALSE;
}
void    fill_entry_file(t_entry *e, struct stat s, const char name[])
{
    e->is_folder = FALSE;
    e->full_name = get_full_name(name);
    e->is_null = FALSE;
}

void fill_entry(t_entry *e, struct stat s, const char name[])
{
    
           switch (s.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device:\tignoring\n");            break;
           case S_IFCHR:  printf("character device\tignoring\n");        break;
           case S_IFDIR:  fill_entry_dir(e, s, name)    ;          break;
           case S_IFIFO:  printf("FIFO/pipe\tignoring\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:   fill_entry_file(e, s, name)    ;           break;
           case S_IFSOCK: printf("socket\tignoring\n");                  break;
           default:       printf("unknown?: %d\n", s.st_mode);   exit(2);             break;
           }

    
}
t_entry try_get_entry(const char    arg[])
{
    t_entry e;
    e = create_null_entry();
    
    struct stat s;
    if (lstat(arg, &s) != -1) 
    {
        fill_entry(&e, s, arg);
    }
    else
    {
        perror("lstat() ");
        
    }
    return (e);
}