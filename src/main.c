//
// Created by mirex on 02.07.2018.
//

#include "ft_ssl.h"

void    print_usage()
{
    ft_putstr(USAGE);
}

void    print_error(char * str)
{
    ft_putstr("ft_ssl: Error: '");
    ft_putstr(str);
    ft_putstr("' is an invalid command.\n\nStandard commands:\n\nMess");
    ft_putstr("age Digest commands:\nmd5\nsha256\n\nCipher commands:\n");
}

int main(int argc, char** argv)
{
    t_list_code *list;

    list = create_list();
    if (argc == 1)
    {
        print_usage();
        return (0);
    }
    if (!ft_strcmp(argv[1], "md5") || !ft_strcmp(argv[1], "sha256"))
    {
        do_md5_sha(list, argc, argv);
    }
    else
        print_error(argv[1]);

    return 0;
}