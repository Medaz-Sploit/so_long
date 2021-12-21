/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 02:38:02 by mazoukni          #+#    #+#             */
/*   Updated: 2021/12/21 07:54:23 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_game(t_so_long *so_long)
{
	int	i;

	if (so_long->map.map)
	{
		i = 0;
		while (i < so_long->map.HEIGHT)
			free(so_long->map.map[i++]);
		free(so_long->map.map);
	}
	free(so_long->game);
}


