#include <so_long.h>

t_so_long *init_data(t_so_long *so_long)
{

}

int read_map(char **argv)
{
    int fd;
    char *line;

    fd = open(argv[1], O_RDONLY);
    if (fd < 1)
        exit_game(1);
    while (get_next_line(fd, &line))
    {
        read_line(line);
        free(line);
        line = NULL;
    }
    read_line(line);
    free(line);
    line = NULL;
}

int main(int argc, char **argv)
{
    t_so_long so_long;

    if (argc == 2)
    {
        so_long = malloc(sizeof(t_so_long));
        if (!so_long)
            exit_game(2);
        if (ft_strncmp(argv[1], ".ber", 4) != 0)
            exit_game(3);
        init_data(so_long);
        read_map(argv);
    }
    else
        exit_game(4);
    return (0);
}
