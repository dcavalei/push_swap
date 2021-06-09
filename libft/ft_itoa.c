/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:05:43 by dcavalei          #+#    #+#             */
/*   Updated: 2021/04/05 16:06:52 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	digit_counter(int n)
{
	int		i;

	i = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	nbr;
	int		i;

	nbr = n;
	i = digit_counter(n);
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	ptr[i] = '\0';
	if (!n)
		ptr[0] = '0';
	if (nbr < 0)
	{
		nbr = -nbr;
		ptr[0] = '-';
	}
	while (nbr)
	{
		ptr[--i] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (ptr);
}
