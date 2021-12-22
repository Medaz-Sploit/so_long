#include "../include/so_long.h"


int	check_ber(char **argv)
{
	int len;

	len = ft_strlen(argv[1]);
	if (argv[1] == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		printf("Error: %s\n", strerror(errno));
	return (1);
}

int main(int argc, char **argv)
{
 	t_so_long *so_long;

	if (argc == 2)
	{
		if (!check_ber(argv))
		{
			printf("Error: invalide argument <name>.ber !\n");
			return (-1);
		}
	}
	else
		printf("Error: %s\n", strerror(errno));
	so_long = init_game(argv[1]);
	mlx_hook(so_long->win_ptr, 2, 0, key_press, "KEY_PRESS");
	mlx_hook(so_long->win_ptr, 3, 0, key_release, "KEY_RELEASE");
	mlx_loop_hook(so_long->mlx_ptr, &game_update, "GAME_UPDATE");
	mlx_hook(so_long->win_ptr, 17, 1L << 5, key_exit, "EXIT_GAME");
	mlx_loop(so_long->mlx_ptr);
	return (0);
}
