#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"

# define TILE_SIZE 32
# define W         13
# define S         1
# define D         2
# define A         0
# define ESC       53

typedef struct s_image
{
    void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}						t_image;

typedef struct s_map
{
    char        **map;
    int         HEIGHT;
    int         WIDTH;
}               t_map;

typedef struct s_player
{
    int         count;
    int         WALK_X;
    int         WALK_Y;
    float       X;
    float       Y;
    float       STEPS;

}              t_player;

typedef struct s_exit
{
    int         count;
    float       X;
    float       Y;
}               t_exit;

typedef struct s_collectible
{
    int         count;
    float       X;
    float       Y;
}               t_collectible;


typedef struct s_so_long
{
    t_image         img;
    int             *get_data;
    void            *img_ptr;
    int             *dst;
    void            *imag;
    void            *mlx_ptr;
    void            *win_ptr;
    void            *new_image;
    t_map           map;
    t_player        player;
    t_exit          exit;
    t_collectible   collectible;
}               t_so_long;

char        **save_map(t_so_long so_long, char *line);
void        init_game(t_so_long so_long);
int         key_release(t_so_long so_long, int keycode);
int         key_press(t_so_long so_long, int keycode);
int         key_exit(void);
void        player_position(t_so_long);
void        texture(t_so_long so_long);
void        sprite(t_so_long so_long);
void        player_mouvement(t_so_long so_long);
void        render(t_so_long so_long);
void        draw_sprite(t_so_long so_long);
int         game_update(t_so_long so_long);


#endif
