/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:14:36 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/20 05:26:34 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char*)src;
	while (n > 0)
	{
		if ((unsigned char)c == *ptr)
		{
			*((unsigned char*)dst) = *ptr;
			return (dst + 1);
			break ;
		}
		*((unsigned char*)dst) = *ptr;
		n--;
		ptr++;
		dst++;
	}
	return (0);
}
