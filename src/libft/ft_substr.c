/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 23:31:27 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/23 01:04:10 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	if (!(sub = malloc(1 + len * sizeof(char))))
		return (NULL);
	if (!len)
		sub[0] = '\0';
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
