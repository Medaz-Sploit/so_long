/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 02:39:16 by mazoukni          #+#    #+#             */
/*   Updated: 2021/12/21 13:33:51 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include "../src/get_next_line/get_next_line.h"
# include "../src/libft/libft.h"

# define TILE_SIZE 32
# define W         13
# define S         1
# define D         2
# define A         0
# define ESC       53

typedef struct s_image
{
	int			width;
	int			height;
	void			*img;
	char			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}		t_image;

typedef struct s_map
{
	char		**tmp;
	char       	 **map;
	int         HEIGHT;
	int         WIDTH;
}               t_map;

typedef struct s_coord
{
	int	X;
	int	Y;
}		t_coord;

typedef struct s_game
{
	t_coord		player;
	t_coord		exit;
	t_coord		*coll;
	int		player_up;
	int		player_down;
	int		player_left;
	int		player_right;
	int		player_move;
	int		player_coll;
	int         WALK_X;
	int         WALK_Y;
	float       STEPS;
	int		count_coll;
	int		count_player;
	int		count_exit;

}              t_game;

typedef struct s_so_long
{
	t_game		*game;
	t_image         *img;
	t_image		*ground;
	int             *get_data;
	void            *img_ptr;
	int             *dst;
	void            *imag;
	void            *mlx_ptr;
	void            *win_ptr;
	void            *new_image;
	t_map           map;
	t_image        	*player;
	t_image		*wall;
	t_image         *exit;
	t_image  	*collectible;
}               t_so_long;

char        **save_map(t_so_long *so_long, char *line);
t_so_long        *init_game(char *filename);
void		so_long_destroy(t_so_long *so_long, char *srt);
int         key_release(t_so_long *so_long, int keycode);
int         key_press(t_so_long *so_long, int keycode);
int         key_exit(t_so_long *so_long);
void        player_position(t_so_long *so_long);
void		read_map(t_so_long *so_long, char *line);
void        read_texture(t_so_long *so_long);
int		isborder(t_so_long *so_long, int i);
void		isvalid(t_so_long *so_long, char *line, int i);
void        sprite(t_so_long *so_long);
void        player_mouvement(t_so_long *so_long);
void        render(t_so_long *so_long);
void        draw_sprite(t_so_long *so_long);
int         game_update(t_so_long *so_long);
void		start_game(t_so_long *so_long, char *filename);
void		free_map(t_so_long *so_long, char *line, char **m, int size);
void		get_coordination(t_so_long *so_long, char *line, int k, int *collectible);
void		move_up(t_so_long *so_long, int x, int y);
void		move_down(t_so_long *so_long, int x, int y);
void		move_left(t_so_long *so_long, int x, int y);
void		move_right(t_so_long *so_long, int x, int y);
void		draw(t_so_long *so_long);
void		destroy_game(t_so_long *so_long);
void		map_init(t_so_long *so_long, char *filename);


#endif
