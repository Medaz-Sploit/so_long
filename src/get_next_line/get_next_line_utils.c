/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:42:07 by mazoukni          #+#    #+#             */
/*   Updated: 2021/04/08 00:25:52 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, ft_strlen(s1) + 1);
	return (copy);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	lsrc;
	size_t	i;

	i = 0;
	lsrc = ft_strlen((char *)src);
	if (n == 0)
		return (lsrc);
	while (src[i] != '\0' && i < n - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (lsrc);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*bf;

	if (s1 && s2)
		i = ft_strlen(s1) + ft_strlen(s2);
	else
		return (NULL);
	bf = (char *)malloc(i + 1);
	if (!bf)
		return (NULL);
	i = -1;
	j = ft_strlen(s1);
	while (s1[++i])
		bf[i] = s1[i];
	i = -1;
	while (s2[++i])
		bf[i + j] = s2[i];
	bf[i + j] = '\0';
	return (bf);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s) + 1;
	while (j--)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
