/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:29:48 by dcavalei          #+#    #+#             */
/*   Updated: 2021/04/06 17:35:31 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

static	int	check_base(char *base)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = get_size(base);
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (i < size)
	{
		while (j < size)
		{
			if (i != j)
			{
				if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int	size;

	if (!check_base(base))
		return ;
	size = get_size(base);
	if (nbr > -1)
	{
		if (nbr >= size)
			ft_putnbr_base_fd(nbr / size, base, fd);
		ft_putchar_fd(base[nbr % size], fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		if (nbr < (-size))
			ft_putnbr_base_fd(nbr / (-size), base, fd);
		ft_putchar_fd(base[nbr % (-size)], fd);
	}
}
