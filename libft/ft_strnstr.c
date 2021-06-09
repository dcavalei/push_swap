/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:25:11 by dcavalei          #+#    #+#             */
/*   Updated: 2021/04/05 16:14:59 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_len;
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	needle_len = ft_strlen(needle);
	while (haystack[i] && n >= i + needle_len)
	{
		if (haystack[i] == *needle
			&& !ft_memcmp(&(haystack[i]), needle, needle_len))
			return ((char *)haystack + i);
		else
			i++;
	}
	return (0);
}
