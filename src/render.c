#include "..include/so_long.h"

int        game_update(t_so_long so_long)
{
    so_long.img = mlx_new_image(so_long.mlx_ptr, so_long.map.WIDTH, so_long.map.HEIGHT);
    so_long.dst = (int *)mlx_get_data_addr(so_long.img, &so_long.img.bits_per_pixel, &so_long.img.line_length, &so_long.img.endian);
    player_mouvment(so_long);
    render(so_long);
    sprite(so_long);
    mlx_put_image_to_window(so_long.mlx_ptr, so_long.win_ptr, so_long.img)
}
