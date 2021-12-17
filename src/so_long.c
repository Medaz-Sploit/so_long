#include "../include/so_long.h"

t_so_long *init_data(t_so_long so_long)
{
    so_long.player.x = 0;
    so_long.player.y = 0;
    so_long.exit.x = 0;
    so_long.exit.y = 0;
    so_long.collectible.x = 0;
    so_long.collectible.y = 0;
    so_long.mlx_ptr = mlx_init();
    so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, so_long.map.WIDTH, so_long.map.HEIGHT, "SO_LONG");
    so_long.img = NULL;
    return (so_long);
}

int read_line (char *line)
{
    int i;

    i = 0;
    if (ft_isspace(line[i]))
        printf("Error: Encounter a space in map file\n");
    if (line[i] != 1 || line[i] != 0)
        printf("Error: Corrupted map file\n");
    save_map(line);

}

int read_map(char **argv)
{
    int fd;
    char *line;

    fd = open(argv[1], O_RDONLY);
    if (fd < 1)
        printf("Error: %s\n", strerror(errno));
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
        ft_bzero(so_long, sizeof(t_so_long));
        if (!so_long)
            printf("Error: %s\n", strerror(errno));
        if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
            printf("Error: %s\n", strerror(errno));
        so_long = init_data(so_long);
        read_map(argv);
        init_game(so_long);
    }
    else
        printf("Error: %s\n", strerror(errno));
    return (0);
}
