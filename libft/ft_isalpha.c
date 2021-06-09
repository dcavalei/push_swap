/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:27:42 by dcavalei          #+#    #+#             */
/*   Updated: 2021/02/15 15:40:57 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
		|| ((unsigned char)c >= 'a' && (unsigned char)c <= 'z'))
		return (1);
	return (0);
}
