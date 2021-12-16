#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define

typedef struct s_so_long
{
    t_map           map;
    t_player        player;
    t_exit          exit;
    t_collectible   collectible;
}               t_so_long;

typedef struct s_map
{
    int         TILE_SIZE;
    int         HIGH;
    int         WIDTH;
}               t_map;

typedef struct s_player
{
    float       x;
    float       y;
    float       steps;

}              t_player;

typedef struct s_exit
{
    float       x;
    float       y;
}               t_exit;

typedef struct s_collectible
{
    float       x;
    float       y;
}               t_collectible;

#endif
