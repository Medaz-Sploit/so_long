/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 23:00:42 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/24 23:01:35 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *str, size_t size)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char*)str;
	while (i < size)
	{
		if (!*s)
			break ;
		i++;
		s++;
	}
	return (i);
}
