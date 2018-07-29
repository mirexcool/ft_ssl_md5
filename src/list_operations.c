//
// Created by mirex on 02.07.2018.
//

#include "ft_ssl.h"

void push_list(t_list_code **b_list, t_code *to_push)
{

}

t_code * create_code()
{
    t_code      *code;

    code = malloc(sizeof(t_code));
    code->md5 = 0;
    code->sha256 = 0;
    code->f_p = 0;
    code->f_q = 0;
    code->f_r = 0;
    code->f_s = 0;
    code->file = 0;
    code->str_to_encode = NULL;
    return  code;
}

t_list_code * create_list()
{
    t_list_code *list;

    list = malloc(sizeof(t_list_code));

    list->code = create_code();
    list->next = NULL;
    return list;
}