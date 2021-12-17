/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:57:12 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/24 04:32:43 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (src < dst)
	{
		while (n != 0)
		{
			*((char*)dst + (n - 1)) = *((char*)src + (n - 1));
			n--;
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
