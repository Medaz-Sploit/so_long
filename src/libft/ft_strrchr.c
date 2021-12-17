/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:02:43 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/15 04:53:51 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;
	int i;

	len = 0;
	i = 0;
	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	while (*s != '\0')
	{
		s++;
		len++;
	}
	s--;
	while (i < len)
	{
		if (*s == (char)c)
			return ((char*)s);
		s--;
		i++;
	}
	return (NULL);
}
