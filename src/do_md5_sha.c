//
// Created by mirex on 02.07.2018.
//
#include "ft_ssl.h"

void do_md5_sha(t_list_code * begin_list, int argc, char** argv )
{
    t_list_code *list;

    list = begin_list;
    get_comm_and_args(begin_list, argc, argv);
    while (list->next)
    {
        if (list->code->file != 0)
            get_string_from_fd(&list->code->str_to_encode, list->code->str_to_encode);
        list = list->next;
    }
    start_encoding(&begin_list);
}

void start_encoding (t_list_code ** begin_list)
{
    t_list_code *list;

    list = *begin_list;
    while (list->next)
    {
//        if (list->code->sha256)
//            do_sha256(&code);
        if (list->code->md5)
            do_md5(list->code);
        list = list->next;
    }
}

void get_comm_and_args (t_list_code * begin_list, int argc, char** argv)
{
    size_t i;

    i = 1;
    while (i < argc)
    {
        put_args_and_flags(&begin_list, argv[i], i);
        i++;
    }
}

void    put_args_and_flags(t_list_code ** begin_list, char *string, int i)
{
    t_list_code *list;

    list = *begin_list;
    while (list->next)
        list = list->next;
    if (i == 1)
    {
        if (!ft_strcmp(string, "md5"))
            list->code->md5 = 1;
        else if (!ft_strcmp(string, "sha256"))
            list->code->sha256 = 1;
    }
    else
        if (ft_strncmp(string, "-", 1) == 0)
        {
            if (ft_strcmp(string, "-p") == 0)
                list->code->f_p = 1;
            else if (ft_strcmp(string, "-q") == 0)
                list->code->f_q = 1;
            else if (ft_strcmp(string, "-r") == 0)
                list->code->f_r = 1;
            else if (ft_strcmp(string, "-s") == 0)
                list->code->f_s = 1;
            else
            {
                ft_putstr("Flag: ");
                ft_putstr(string);
                ft_putstr(" not supported.\n");
                exit (1);
            }
        }
        else
        {
            list->code->str_to_encode = ft_strdup(string);
            list->next = create_list();
            list->next->code->sha256 = list->code->sha256;
            list->next->code->md5 = list->code->md5;
        }
}

