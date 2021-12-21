#include "../include/so_long.h"


void	render(t_so_long *so_long)
{
	so_long->mlx_ptr = mlx_init();
	if (so_long->mlx_ptr == 0)
		so_long_destroy(so_long, "mlx_init(): CAN'T LOAD MLX!!\n");
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, so_long->map.WIDTH * TILE_SIZE, so_long->map.HEIGHT * TILE_SIZE);
	if (so_long->img == 0)
		so_long_destroy(so_long, "mlx_new_image(): CAN'T CREATE AN IMAGE!!\n");
}


static void	is_moved(t_so_long *so_long, int x, int y)
{
	if (so_long->game->player.X != x || so_long->game->player.Y != y)
	{
		so_long->game->player_move++;
		printf("Player moved: %d so far...!\n", so_long->game->player_move);
	}
}

static void	is_collectible(t_so_long *so_long)
{
	int	k;

	k = 0;
	while (k < so_long->game->count_coll)
	{
		if (so_long->game->coll[k].X == so_long->game->player.X
			&& so_long->game->coll[k].Y == so_lomg->game->player.Y)
		{
			so_long->game->coll[k].X = -1;
			so_long->game->coll[k].Y = -1;
			so_long->game->player_coll++;
		}
		k++;
	}
}

int        game_update(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->game->player.X;
	y = so_long->game->player.Y;
	if (so_long->game->player_up != 0)
		move_up(so_long, x, y);
	else if (so_long->game->player_down != 0)
		move_down(so_long, x, y);
	else if (so_long->game->player_left != 0)
		move_left(so_long, x, y);
	else if (so_long->game->player_right != 0)
		move_right(so_long, x. y);
	is_moved(so_long, x, y);
	is_collectible(so_long);
	draw(so_long);
	if (so_long->game->exit.X == so_long->game->player.X
		&& so_long->game->exit.Y == so_long->player.Y)
		if (so_lomg->game->count_coll == so_long->game->player_coll)
			so_long_destroy(so_long, NULL);
	
   // so_long->imag = mlx_new_image(so_long->mlx_ptr, so_long->map.WIDTH, so_long->map.HEIGHT);
    //so_long->dst = (int *)mlx_get_data_addr(so_long->imag, &so_long->img.bits_per_pixel, &so_long->img.line_length, &so_long->img.endian);
    //player_mouvement(so_long);
    //render(so_long);
    //draw_sprite(so_long);
    //mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->imag, 0, 0);
}
