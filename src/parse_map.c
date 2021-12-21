#include "../include/so_long.h"

void	get_coordination(t_so_long *so_long, char *line, int k, int *collectible)
{
	if (line[i] == 'P')
	{
		so_long->game.player.X = k % (so_long->map.WIDTH + 1);
		so_long->game.player.Y = k / (so_long->map.WIDTH + 1);
		line[k] = '0';
	}
	else if (line[k] == 'E')
	{
		so_long->game.exit.X = k % (so_long->map.WIDTH+ 1);
		so_long->game.exit.Y = k / (so_long->map.WIDTH + 1);
		line[k] = '0';
	}
	else if (line[k] == 'C')
	{
		so_long->game.coll[*collectible].X = k % (so_long->map.WIDTH + 1);
		so_long->game.coll[*collectible].Y = k / (so_long->map.WIDTH + 1);
		line[k] = '0';
		(*collectible)++;
	}
}

void	free_map(t_so_long *so_long, char *line, char **m, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	so_long->map.map = 0;
	free(line);
	printf("Error: Map parsing: malloc()!\n");
	so_long_destroy(so_long);
}

void	isvalid(t_so_long *so_long, char *line, int i)
{
	if (line[i] == 'P')
		so_long->game.count_player++;
	else if (line[i] == 'E')
		so_long->game.count_exit++;
	else if (line[i] == 'C')
		so_long->game.count_coll++;
	else if (line[i] == '1' || line[i] == '0')
		return ;
	else
	{
		free(line);
		printf("Error: Map content is invalid!\n");
		so_long_destroy(so_long);
	}
}

int	isborder(t_so_long *so_long, int i)
{
	if (i < so_long->map.WIDTH
		|| i > (so_long->map.WIDTH + 1) * (so_long->map.HEIGHT - 1)
		|| i % (so_long->map.WIDTH + 1) == 0
		|| i % (so_long->map.WIDTH + 1) == so_long->map.WIDTH -1)
		return (1);
	return (0);

}
