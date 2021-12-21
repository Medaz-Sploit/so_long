/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 08:23:16 by mazoukni          #+#    #+#             */
/*   Updated: 2021/12/21 09:41:57 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_so_long *so_long, int x, int y)
{
	if (so_long->map.map[y - 1][x] == 0)
		so_long->game->player.Y = -1;
}

void	move_down(t_so_long *so_long, int x, int y)
{
	if (so_long->map.map[y + 1][x] == 0)
		so_long->game->player.Y += 1;
}

void	move_left(t_so_long *so_long, int x, int y)
{
	if (so_long->map.map[y][x + 1] == 0)
		so_long->game->player.X -= 1;
}

void	move_right(t_so_long *so_long, int x, int y)
{
	if (so_long->map.map[y][x + 1] == 0)
		so_long->game->player.X += 1;
}

