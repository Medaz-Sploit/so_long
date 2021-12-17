/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:55:56 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/24 22:59:53 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(s) + 1;
	while (j--)
	{
		if (s[i] == (unsigned char)c)
			return ((char*)(s + i));
		i++;
	}
	return (0);
}
