/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:19:43 by dcavalei          #+#    #+#             */
/*   Updated: 2021/04/20 15:18:12 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_machine_thx_norminette(char **ptr_1, char **ptr_2)
{
	if (ptr_1)
	{
		free(*ptr_1);
		*ptr_1 = NULL;
	}
	if (ptr_2)
	{
		free(*ptr_2);
		ptr_2 = NULL;
	}
}

void	output_and_shift(char **buffer, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	*line = ft_substr(*buffer, 0, i);
	if ((*buffer)[i] == '\n')
		i++;
	temp = ft_strdup((*buffer) + i);
	free(*buffer);
	*buffer = temp;
}

void	realloc_temp(char **temp, int *len, int next_ammount)
{
	char	*ptr;
	int		i;

	while (*len <= next_ammount)
		*len += DEFAULT_SIZE;
	ptr = malloc(sizeof(char) * (*len));
	if (!ptr)
		return ;
	i = 0;
	while (i < (*len))
		ptr[i++] = '\0';
	i = 0;
	while ((*temp)[i])
	{
		ptr[i] = (*temp)[i];
		i++;
	}
	free(*temp);
	(*temp) = ptr;
}

/*
**		thx to norminettev3
**
**		i = storage[0]
**		len = storage[1]
**		r = storage[2]
**		total = storage[3]
*/

char	*new_temp(int fd)
{
	char	*temp;
	int		storage[4];

	storage[1] = DEFAULT_SIZE;
	while (storage[1] <= BUFFER_SIZE)
		storage[1] += DEFAULT_SIZE;
	temp = malloc(sizeof(char) * storage[1]);
	storage[0] = 0;
	while (storage[0] < storage[1])
		temp[storage[0]++] = '\0';
	storage[3] = 0;
	storage[2] = read(fd, temp + storage[3], BUFFER_SIZE);
	while (storage[2])
	{
		storage[3] += storage[2];
		storage[0] = 0;
		if (storage[1] < storage[3] + storage[2] + 1)
			realloc_temp(&temp, &storage[1], storage[3] + storage[2]);
		while (temp[storage[0]])
			if (temp[storage[0]++] == '\n')
				return (temp);
		storage[2] = read(fd, temp + storage[3], BUFFER_SIZE);
	}
	return (temp);
}

int	ft_get_next_line(int fd, char **line)
{
	static char	*buffer[1024];
	char		*temp;
	char		*new;
	int			ret;

	ret = 1;
	if (read(fd, 0, 0) < 0 || !line)
		return (-1);
	if (!buffer[fd])
		buffer[fd] = ft_substr("", 0, 0);
	if (ft_strchr(buffer[fd], '\n'))
		output_and_shift(&buffer[fd], line);
	else
	{
		temp = new_temp(fd);
		new = ft_strjoin(buffer[fd], temp);
		free_machine_thx_norminette(&temp, &buffer[fd]);
		buffer[fd] = new;
		if (!ft_strchr(buffer[fd], '\n'))
			ret = 0;
		output_and_shift(&buffer[fd], line);
	}
	if (ret == 0)
		free_machine_thx_norminette(&buffer[fd], NULL);
	return (ret);
}
