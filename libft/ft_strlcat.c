/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:12:39 by dcavalei          #+#    #+#             */
/*   Updated: 2021/02/23 16:36:36 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	attempt_size;
	size_t	i_src;
	size_t	i_dest;

	if (dest_size == 0)
		return (ft_strlen(src));
	else if (dest_size < ft_strlen(dest))
		attempt_size = ft_strlen(src) + dest_size;
	else
		attempt_size = ft_strlen(src) + ft_strlen(dest);
	i_dest = 0;
	while (dest[i_dest])
		i_dest++;
	i_src = 0;
	while (src[i_src] && i_dest < dest_size - 1)
	{
		dest[i_dest] = src[i_src];
		i_dest++;
		i_src++;
	}
	dest[i_dest] = '\0';
	return (attempt_size);
}
