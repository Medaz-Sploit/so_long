/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 04:04:41 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/24 23:00:30 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*bf;

	if (s1 && s2)
		i = ft_strlen(s1) + ft_strlen(s2);
	else
		return (NULL);
	bf = (char*)malloc(i + 1);
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
