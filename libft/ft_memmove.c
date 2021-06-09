/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:58:39 by dcavalei          #+#    #+#             */
/*   Updated: 2021/04/05 16:12:07 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (dest < src)
		while (++i < n)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	else
	{
		while (--n >= 0)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
			if (!n)
				return (dest);
		}
	}
	return (dest);
}
