/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 23:35:20 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/25 01:54:34 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*free_tab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

static	char	word(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (str[i] == c)
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
			{
				i++;
				continue;
			}
			count++;
		}
		i++;
	}
	return (count);
}

static	int		chars(char *str, char c)
{
	int		i;

	i = 1;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	return (i);
}

char			**spliter(char const *str, char c, int i, int j)
{
	char		**tab;
	char		*ptr;

	if (!str)
		return (NULL);
	ptr = (char*)str;
	if (!(tab = (char **)malloc((1 + word((char*)str, c) + 1)
					* sizeof(char*))))
		return (NULL);
	while (*ptr != '\0')
	{
		while (*ptr == c)
			ptr++;
		if (*ptr == '\0')
			break ;
		if (!(tab[++i] = (char *)malloc(1 + chars(ptr, c) * sizeof(char))))
			if (!(free_tab(tab, i - 1)))
				break ;
		insert_element(ptr, tab, i, c);
		ptr += chars(ptr, c);
	}
	tab[j] = 0;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char		**split;

	if (!s)
		return (0);
	split = spliter(s, c, -1, word((char*)s, c));
	return (split);
}
