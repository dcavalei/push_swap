/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:07:24 by dcavalei          #+#    #+#             */
/*   Updated: 2021/04/05 16:12:42 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (!str[i])
			break ;
		while (str[i] && str[i] != c)
			i++;
		words++;
	}
	return (words);
}

char	**ft_split(char const *str, char c)
{
	char	**ptr;
	int		current;
	int		ptr_index;
	int		i;

	ptr = malloc(sizeof(char *) * (word_counter(str, c) + 1));
	if (!ptr)
		return (NULL);
	ptr[word_counter(str, c)] = 0;
	ptr_index = 0;
	while (*str && *str == c)
		str++;
	current = 0;
	while (str[current])
	{
		i = current;
		while (str[current] && str[current] != c)
			current++;
		ptr[ptr_index++] = ft_substr(str, i, current - i);
		while (str[current] && str[current] == c)
			current++;
	}
	return (ptr);
}
