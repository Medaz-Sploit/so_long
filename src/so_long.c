#include "../include/so_long.h"

t_so_long init_data(t_so_long so_long)
{
    so_long.player.X = 0;
    so_long.player.Y = 0;
    so_long.exit.X = 0;
    so_long.exit.Y = 0;
    so_long.collectible.X = 0;
    so_long.collectible.Y = 0;
    so_long.mlx_ptr = mlx_init();
    so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, so_long.map.WIDTH, so_long.map.HEIGHT, "SO_LONG");
    so_long.imag = NULL;
    return (so_long);
}

int read_line(t_so_long so_long, char *line)
{
    int i;

    i = 0;
    if (ft_isspace(line[i]))
        printf("Error: Encounter a space in map file\n");
    if (line[i] != 1)
        printf("Error: Corrupted map file\n");
    save_map(so_long, line);
    return (0);
}

int read_map(t_so_long so_long, char **argv)
{
    int fd;
    char *line;

    fd = open(argv[1], O_RDONLY);
    if (fd < 1)
        printf("Error: %s\n", strerror(errno));
    while (get_next_line(fd, &line))
    {
        read_line(so_long, line);
        free(line);
        line = NULL;
    }
    read_line(so_long, line);
    free(line);
    line = NULL;
    return (0);
}

int main(int argc, char **argv)
{
    t_so_long so_long;

    if (argc == 2)
    {
        so_long = *(t_so_long *)malloc(sizeof(t_so_long));
        if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
            printf("Error: %s\n", strerror(errno));
        so_long = init_data(so_long);
        read_map(so_long, argv);
        init_game(so_long);
    }
    else
        printf("Error: %s\n", strerror(errno));
    return (0);
}
