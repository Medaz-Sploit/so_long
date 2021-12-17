/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 23:27:52 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/24 22:57:44 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_nb_size(long int nb)
{
	int		size;

	size = 0;
	while (nb)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nb)
{
	char		*str;
	long int	number;
	int			index;

	number = nb;
	if (number < 0)
		number *= -1;
	index = get_nb_size(number) + ((nb <= 0) ? 1 : 0);
	if (!(str = (char*)malloc(sizeof(char) * index + 1)))
		return (0);
	if (number == 0)
		str[0] = 48;
	str[index] = '\0';
	if (nb < 0)
		str[0] = '-';
	while (number)
	{
		str[--index] = (char)(number % 10 + 48);
		number /= 10;
	}
	return (str);
}
