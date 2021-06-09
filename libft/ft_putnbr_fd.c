/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:02:39 by dcavalei          #+#    #+#             */
/*   Updated: 2021/02/19 14:08:06 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n <= -10)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-(n / 10), fd);
		ft_putchar_fd(-(n % 10) + '0', fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd(-n + '0', fd);
	}
}
