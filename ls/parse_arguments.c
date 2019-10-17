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