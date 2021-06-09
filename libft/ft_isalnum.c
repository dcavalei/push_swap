/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:38:22 by dcavalei          #+#    #+#             */
/*   Updated: 2021/04/05 16:05:33 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
		|| ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
		|| ((unsigned char)c >= '0' && (unsigned char)c <= '9'))
		return (1);
	return (0);
}
