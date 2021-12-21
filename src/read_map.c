#include "../include/so_long.h"


void	map_width(t_so_long *so_long, char *line)
{
	so_long->map.WIDTH = 0;
	while(line[so_long->map.WIDTH] && line[so_long->map.WIDTH] != '\n')
		so_long->map.WIDTH++;
	if (so_long->map.WIDTH == 0 || line[so_long->map.WIDTH] == 0)
	{
		free(line);
	}
}

void	map_height(t_so_long *so_long, char *line)
{
	int	i;
	int 	j;

	so_long->map.HEIGHT = 1;
	i = so_long->map.WIDTH;
	while (line[i] != 0)
	{
		j = 0;
		while (line[i + j] != 0 && line[i + j] != '\n')
			j++;
		if (so_long->map.WIDTH != j)
		{
			free(line);
			printf("Error: Map must be square!\n");
			so_long_destroy(so_long);
		}
		i += so_long->map.WIDTH + 1;
		so_long->map.HEIGHT++;
	}
}

void	ismap_valid(t_so_long *long, char *line)
{
	int	i;

	i = -1;
	while (line[++i] != 0)
	{
		if (line[i] == '\n')
			continue;
		if (isborder(so_long, i))
		{
			if (line[i] != '1')
			{
				free(line);
				printf("Error: map must be surrounded by walls!\n");
				so_long_destroy(so_long);
			}
		}
		else
			isvalid(so_long, line, i);
	}
	if (so_long->game.count_player != 1 
		|| so_long->game.count_exit != 1 
		|| so_long->game.count_coll < 1)
	{
		free(line);
		printf("Error: Map Configuration is invalid!\n");
		so_long_destroy(so_long);
	}
}

void	map_parsing(t_so_long *so_long, char *line)
{
	int	width;
	int	height;
	int	k;
	int	collectible;

	collectible = 0;
	k = 0;
	height = -1;
	while (++height < so_long->map.HEIGHT)
	{
		so_long->map.map[height] = (char *)malloc(sizeof(char) * so_long->map.WIDTH);
		if (so_long->map.map[height] == 0)
			free_map(so_long, line, so_long->map.map, height);
		width = 0;
		while (width < so_long->map.WIDTH)
		{
			get_coordination(so_long, line, k, &collectible);
			so_long->map.map[height][width++] = line[k++];
		}
		k++;
	}
}

void	read_map(t_so_long *so_long, char *line)
{
	map_width(so_long, line);
	map_height(so_long, line);
	ismap_valid(so_long, line);
	so_long->game.coll = (t_coord *)malloc(sizeof(t_coord) \
				* so_long->game.count_coll);
	if (so_long->game.coll == 0)
	{
		free(line);
		printf("Error: MALLOC FAILURE!!\n");
		so_long_destroy(so_long);
	}
	so_long->map.map = (char **)malloc(sizeof(char *) * so_long->map.HEIGHT);
	if (so_long->map.map == 0)
	{
		free(line);
		printf("Error: MALLOC FAILURE!!\n");
		so_long_destroy(so_long);
	}
	map_parsing(so_long, line);
}
