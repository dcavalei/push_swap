/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:52:06 by dcavalei          #+#    #+#             */
/*   Updated: 2021/04/05 16:13:47 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i_src;
	size_t	i_dest;

	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr || !s1 || !s2)
		return (NULL);
	i_dest = 0;
	i_src = 0;
	while (s1[i_src])
		ptr[i_dest++] = s1[i_src++];
	i_src = 0;
	while (s2[i_src])
		ptr[i_dest++] = s2[i_src++];
	ptr[i_dest] = '\0';
	return (ptr);
}
