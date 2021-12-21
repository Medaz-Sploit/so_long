/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_destory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 02:41:36 by mazoukni          #+#    #+#             */
/*   Updated: 2021/12/21 07:54:11 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_long_destroy(t_so_long *so_long, char *str)
{
	if (so_long)
	{
		if (so_long->ground)
			mlx_destroy_image(so_long->mlx_ptr, so_long->ground);
		if (so_long->wall)
			mlx_destroy_image(so_long->mlx_ptr, so_long->wall);
		if (so_long->collectible)
			mlx_destroy_image(so_long->mlx_ptr, so_long->collectible);
		if (so_long->exit)
			mlx_destroy_image(so_long->mlx_ptr, so_long->exit);
		if (so_long->player)
			mlx_destroy_image(so_long->mlx_ptr, so_long->player);
		if (so_long->imag)
			mlx_destroy_image(so_long->mlx_ptr, so_long->imag);
		if (so_long->win_mlx)
			mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
		if (so_long->mlx_ptr)
			mlx_destroy_display(so_long->mlx_ptr);
		if (so_long)
			destroy_game(so_long);
		free(so_long);
	}
	printf("%s\n", str);
	printf("GAME EXITED SUCCESSFULLY!\n");
}
