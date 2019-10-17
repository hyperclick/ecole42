#include "ls.h"
void    print_usage()
{}
void    print_no_such_file(const char    arg[])
{
printf("ls: cannot access '%s': No such file or directory\n", arg);
}
BOOL    try_parse_option(t_input input, const char    arg[])
{
    return (TRUE);
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
	char* sub = ft_strsub(name, 0, pos);
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

void     parse_arguments_add_entry(t_input *input, t_entry e)
{
    if (e.is_folder)
    {
        input->folders[input->folders_count++] = e;
        if (input->folders_count > MAX_FSO_IN_DIR)
        {
            printf("MAX_FSO_IN_DIR reached \n");
            exit(3);
        }
    }
    else
    {
        input->files[input->files_count++] = e;
        if (input->files_count > MAX_FSO_IN_DIR)
        {
            printf("MAX_FSO_IN_DIR reached \n");
            exit(4);
        }
    }
}
t_input create_empty_input()
{
    t_input input;
    input.files_count = 0;
    input.folders_count = 0;
    return (input);
}
t_input	parse_arguments(int c, const char *args[])
{
t_input input;
const char    *arg;

input = create_empty_input();

for (int i = 0; i< c; i++)
{
    arg = args[i];
    t_entry e = try_get_entry(arg);
    if (!is_null_entry(e))
    {
        parse_arguments_add_entry(&input, e);
        continue;
    }
    if (arg[0] != '-')
    {
        print_no_such_file(arg);
        continue;
    }
    if (!try_parse_option(input, arg))
    {
        print_usage();
        exit (1);
    }
}
return (input);
}