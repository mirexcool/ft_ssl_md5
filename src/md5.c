//
// Created by mirex on 02.07.2018.
//

#include "ft_ssl.h"

char * get_binar_massage(const char * massage)
{
    char    *binar_massage;
    char    *binar_char;
    char *ptr;

    binar_char = ft_strnew(8);
    binar_massage = ft_strnew(0);

    while(*massage != '\0')
    {
        binar_char = ft_itoa_unsigned(*massage, 2, 'x');
        while (ft_strlen(binar_char) != 8)
        {
            ptr = binar_char;
            binar_char = ft_strjoin("0", binar_char);
            ft_strdel(&ptr);
        }
        ptr = binar_char;
        binar_massage = ft_strjoin(binar_massage, binar_char);
        ft_strdel(&ptr);
        massage++;
    }
    return binar_massage;
}

void do_md5(t_code * code )
{
    char *encoding;

    get_binar_massage(code->str_to_encode);
    encoding = get_binar_massage(code->str_to_encode);
    ft_putendl(encoding);
    encoding[ft_strlen((encoding))] = 0x00;
    ft_putendl(encoding);
}
