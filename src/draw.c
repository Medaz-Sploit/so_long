/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:42:32 by mazoukni          #+#    #+#             */
/*   Updated: 2021/12/21 12:45:38 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	draw_square(t_so_long *so_long, t_image *img, int x, int y)
{
	unsigned int	color;
	int		i;
	int		j;

	j = 0;
	while (j < TILE_SIZE)
	{
		i = 0;
		while (i < TILE_SIZE)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(so_long->img, x + i, y + i, color);
			i++;
		}
		j++;
	}
}

static void	draw_env(t_so_long *so_long, int i, int j)
{
	int	k;

	if (so_long->game->exit.X == i && so_long->game->exit.Y == j)
		draw_square(so_long, so_long->exit, i * TILE_SIZE, j * TILE_SIZE);
	k = -1;
	while (++k < so_long->game->count_coll)
		if (so_long->game->coll[k].X == i && so_long->game->coll[k].Y == j)
			draw_square(so_long, so_long->collectible, i * TILE_SIZE, j * TILE_SIZE);
	if (so_long->game->player.X == i && so_long->game->player.Y == j)
		draw_square(so_long, so_long->player, i * TILE_SIZE, j * TILE_SIZE);
}

static void	draw_map(t_so_long *so_long)
{
	int	i;
	int 	j;

	j = 0;
	while (j < so_long->map.HEIGHT)
	{
		i = 0;
		while (i < so_long->map.WIDTH)
		{
			if (so_long->map.map[j][i] == 1)
				draw_square(so_long, so_long->wall, i * TILE_SIZE, j * TILE_SIZE);
			else
				draw_square(so_long, so_long->ground, i * TILE_SIZE, j * TILE_SIZE);
			draw_env(so_long, i, j);
			i++;
		}
		j++;
	}
}

void	draw(t_so_long *so_long)
{
	draw_map(so_long);
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->img, 0, 0);
}
