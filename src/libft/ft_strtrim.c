/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:26:39 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/24 23:04:22 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	find_start(char const *s1, int *ptr, int *end, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1[*ptr])
		{
			(*ptr)++;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	while (set[i])
	{
		if (set[i] == s1[*end] && *end > *ptr)
		{
			(*end)--;
			i = 0;
		}
		else
			i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		end;
	int		ptr;
	int		i;

	ptr = 0;
	i = 0;
	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1) - 1;
	find_start(s1, &ptr, &end, set);
	if (!(s = (char*)malloc(end - ptr + 2)))
		return (NULL);
	while (ptr < end + 1)
	{
		s[i] = s1[ptr];
		i++;
		ptr++;
	}
	s[i] = '\0';
	return (s);
}
