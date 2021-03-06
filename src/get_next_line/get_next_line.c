/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:44:15 by mazoukni          #+#    #+#             */
/*   Updated: 2021/12/17 21:46:53 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_line(int fd, char **tmp)
{
	char	*buff;
	char	*tmp1;
	int		ret;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		tmp1 = *tmp;
		*tmp = ft_strjoin(*tmp, buff);
		free(tmp1);
		tmp1 = NULL;
		if (ft_strchr(*tmp, '\n'))
			break ;
	}
	free(buff);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	int				i;
	int				ret;
	static char		*tmp;
	char			*tmp1;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 0 || line == NULL || read(fd, NULL, 0))
		return (-1);
	if (!tmp)
		tmp = ft_strdup("");
	ret = read_line(fd, &tmp);
	while (tmp[i] && (tmp[i] != '\n'))
		i++;
	*line = ft_substr(tmp, 0, i);
	if (tmp[i] != '\n' && !ret)
	{
		free(tmp);
		tmp = NULL;
		return (0);
	}
	tmp1 = tmp;
	tmp = ft_strdup(tmp + i + 1);
	free(tmp1);
	return (1);
}
