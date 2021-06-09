/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:10:06 by dcavalei          #+#    #+#             */
/*   Updated: 2021/04/05 16:15:25 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	final;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	final = ft_strlen(s1) - 1;
	while (start <= final && ft_strchr(set, s1[start]))
		start++;
	while (final && ft_strchr(set, s1[final]))
		final--;
	return (ft_substr(s1, start, final - start + 1));
}
