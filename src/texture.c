#include "../include/so_long.h"

void	load_texture(t_so_long *so_long, t_image **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(so_long->mlx_ptr, path, &width, &height);
	(*img)->width = width;
	(*img)->height = height;
}

void	read_texture(t_so_long *so_long)
{
	load_texture(so_long, &so_long->player, "./textures/player.xpm");
	load_texture(so_long, &so_long->exit, "./textures/helicopter.xpm");
	load_texture(so_long, &so_long->collectible, "./textures/gas.xpm");
	load_texture(so_long, &so_long->wall, "./textures/wall.xpm");
	load_texture(so_long, &so_long->ground, "./textures/sand.xpm");
}
