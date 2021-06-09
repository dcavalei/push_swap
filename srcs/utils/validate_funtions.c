/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_funtions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:37:00 by dcavalei          #+#    #+#             */
/*   Updated: 2021/06/09 16:22:29 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_input(char *str)
{
	int	i;

	if (!(*str))
		return (0);
	i = 0;
	if (str[i] == '-' && str[i + 1])
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return ((ft_atol(str) == (long)ft_atoi(str)));
}

static int	array_contains_number(int *array, int number, int size_of_array)
{
	int	i;

	i = 0;
	while (i < size_of_array)
	{
		if (array[i] == number)
			return (1);
		i++;
	}
	return (0);
}

int	has_repeated_numbers(t_list *stack_a)
{
	int	*tmp;
	int	stack_size;
	int	i;

	stack_size = ft_lstsize(stack_a);
	tmp = malloc(sizeof(int) * stack_size);
	if (!tmp)
		return (0);
	i = -1;
	while (++i < stack_size)
	{
		tmp[i] = ctoi(stack_a);
		if (array_contains_number(tmp, tmp[i], i))
		{
			free(tmp);
			return (1);
		}
		stack_a = stack_a->next;
	}
	free(tmp);
	return (0);
}

void	create_stacks(t_list **stack_a, t_list **stack_b, int argc, char **argv)
{
	int	*tmp;
	int	i;

	*stack_a = NULL;
	*stack_b = NULL;
	i = 0;
	while (++i < argc)
	{
		tmp = malloc(sizeof(int));
		if (!tmp || !validate_input(argv[i]))
			close_program(stack_a, stack_b, 1);
		*tmp = ft_atoi(argv[i]);
		ft_lstadd_front(stack_a, ft_lstnew(tmp));
	}
}

void	close_program(t_list **stack_a, t_list **stack_b, int status)
{
	if (stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b)
		ft_lstclear(stack_b, free);
	if (status == 1)
		ft_putstr_fd("Error\n", 2);
	exit(status);
}
