/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:40:43 by dcavalei          #+#    #+#             */
/*   Updated: 2021/04/06 15:53:18 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (((unsigned char)c >= 9 && (unsigned char)c <= 13)
		|| (unsigned char)c == ' ')
		return (1);
	return (0);
}
