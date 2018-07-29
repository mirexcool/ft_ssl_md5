//
// Created by mirex on 02.07.2018.
//

#ifndef MD5_SHA256_FT_SSL_H
#define MD5_SHA256_FT_SSL_H

#include "unistd.h"
#include <stdio.h>

#include "get_next_line.h"
#include "libft/libft.h"

#define USAGE "usage: ft_ssl command [command opts] [command args]"
#define ERROR_COMMAND "ft_ssl: Error: 'foobar' is an invalid command. Standard commands:\n Message Digest commands:\n md5\n sha256\n Cipher commands:"

typedef struct s_code
{
    int md5;
    int sha256;
    int f_p;
    int f_q;
    int f_r;
    int f_s;
    int file;
    char * str_to_encode;
}              t_code;

typedef struct s_list_code
{
    struct s_code       *code;
    struct s_list_code  *next;

} t_list_code;

void            do_md5_sha(t_list_code * begin_list, int argc, char ** argv);
void            get_string_from_fd(char ** str_to_encode, char *file_name);

void            push_list(t_list_code **b_list, t_code *to_push);
t_list_code     * create_list();

void            do_md5(t_code * code );



#endif //MD5_SHA256_FT_SSL_H
