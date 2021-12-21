#include "../include/so_long.h"

int        game_update(t_so_long *so_long)
{
    so_long->imag = mlx_new_image(so_long->mlx_ptr, so_long->map.WIDTH, so_long->map.HEIGHT);
    so_long->dst = (int *)mlx_get_data_addr(so_long->imag, &so_long->img.bits_per_pixel, &so_long->img.line_length, &so_long->img.endian);
    //player_mouvement(so_long);
    //render(so_long);
    //draw_sprite(so_long);
    mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->imag, 0, 0);
    return (0);
}
