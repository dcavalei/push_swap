/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:01:59 by dcavalei          #+#    #+#             */
/*   Updated: 2021/04/05 16:14:27 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *src, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!ptr || !src || !f)
		return (NULL);
	while (i < ft_strlen(src))
	{
		ptr[i] = f(i, src[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
