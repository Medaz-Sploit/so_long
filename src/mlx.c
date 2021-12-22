/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medazsploit <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:09:09 by medazsploit       #+#    #+#             */
/*   Updated: 2021/12/21 14:18:02 by medazsploit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

unsigned int	mlx_get_pixel(t_image *img, int x, int y)
{
	return (*(unsigned int *)
		(img->addr + (x * img->bits_per_pixel / 8 + y * img->line_length)));
}

void	mlx_draw_pixel(t_image *img, int x, int y, int color)
{
	char			*target;

	target = img->addr + (x * img->bits_per_pixel / 8 + y * img->line_length);
	*(unsigned int *)target = color;
}

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}
