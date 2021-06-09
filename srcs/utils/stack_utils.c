/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:27:30 by dcavalei          #+#    #+#             */
/*   Updated: 2021/06/09 16:22:38 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_list *stack)
{
	t_list	*tmp_stack;
	t_list	*current;
	int		*tmp_number;
	int		stack_size;
	int		i;

	if (!stack)
		return (0);
	tmp_stack = NULL;
	while (stack)
	{
		tmp_number = malloc(sizeof(int));
		*tmp_number = ctoi(stack);
		ft_lstadd_front(&tmp_stack, ft_lstnew(tmp_number));
		stack = stack->next;
	}
	sort_low_efficient(tmp_stack);
	stack_size = ft_lstsize(tmp_stack);
	current = tmp_stack;
	i = -1;
	while (++i < (stack_size / 2))
		current = current->next;
	i = ctoi(current);
	ft_lstclear(&tmp_stack, free);
	return (i);
}

int	get_max(t_list *stack)
{
	t_list	*current;
	int		trigger;
	int		max;

	current = stack;
	trigger = 1;
	while (current)
	{
		if (trigger)
		{
			max = *(int *)(current->content);
			trigger--;
		}
		else if (max < *(int *)(current->content))
			max = *(int *)(current->content);
		current = current->next;
	}
	return (max);
}

int	get_min(t_list *stack)
{
	t_list	*current;
	int		trigger;
	int		min;

	current = stack;
	trigger = 1;
	while (current)
	{
		if (trigger)
		{
			min = *(int *)(current->content);
			trigger--;
		}
		else if (min > *(int *)(current->content))
			min = *(int *)(current->content);
		current = current->next;
	}
	return (min);
}

int	ctoi(t_list *stack)
{
	return (*((int *)(stack->content)));
}

int	is_sorted(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current->next)
	{
		if (ctoi(current->next) > ctoi(current))
			return (0);
		current = current->next;
	}
	return (1);
}
