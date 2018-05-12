#include "ft_ssl_md5.h"


#include "stdio.h"

void read_from_stdin()
{
    char *line;

    while (get_next_line(1, &line))
        write(1, line, ft_strlen(line));
}

int check_pattrerns(int argc, char** argv) {
    t_crypto structure;
    int i;

    i = 1;
    if (!ft_strcmp(argv[i], "md5") || !ft_strcmp(argv[i], "sha256") || !ft_strcmp(argv[i], "whirpool"))
    {
        write(1, argv[i], ft_strlen(argv[i]));
        structure.algo = argv[i++];
    }
    else
    {
        write (1, "Error: ", 8);
            write (1, argv[i], ft_strlen(argv[i]));
            write (1, " is not a command!\n", 19);
        return (0);
    }
    while (i++ < argc)
    {
        if (ft_strcmp(argv[i], "-p"))
            structure.flag_p = 1;
        else if (ft_strcmp(argv[i], "-q"))
            structure.flag_p = 1;
        else if (ft_strcmp(argv[i], "-r"))
            structure.flag_p = 1;
        else if (ft_strcmp(argv[i], "-s"))
            structure.flag_p = 1;
        else {
            write (1, "Error: ", 8);
            write (1, argv[i], ft_strlen(argv[i]));
            write (1, " is not a command!\n", 19);
            return (0);
        }
    }
}

void get_argc(int argc, char** argv)
{
    int error;

    error = check_pattrerns(argc, argv);
    if (error == 0)
        write(1, "error", 5);
}

int read_from_argv(int argc, char** argv)
{
    char* usage;

    usage = ft_strnew(7);
    usage = "usage: ";

    if (argc == 1)
    {
        usage = ft_strjoin(usage, argv[0]);
        usage = ft_strjoin(usage, " command [command opts] [command args]\n");
        write(1, usage, ft_strlen(usage));
        return (0);
    }
    else if(argc > 1)
    {

        get_argc(argc, argv);
        return (0);
    }
    else
        return (1);
}

int main(int argc, char** argv)
{
    if (argc > 1 || argc == 1)
        if (read_from_argv(argc, argv))
            read_from_stdin();
    return 0;
};