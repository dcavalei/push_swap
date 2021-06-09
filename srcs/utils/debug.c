/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:33:46 by dcavalei          #+#    #+#             */
/*   Updated: 2021/06/08 18:15:27 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*current;

	ft_putstr_fd("-------------------\n", 1);
	ft_putstr_fd("[stack A]|", 1);
	current = stack_a;
	while (current)
	{
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(*((int *)(current->content)), 1);
		current = current->next;
	}
	ft_putstr_fd("\n[stack B]|", 1);
	current = stack_b;
	while (current)
	{
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(*((int *)(current->content)), 1);
		current = current->next;
	}
	ft_putstr_fd("\n-------------------\n", 1);
}

void	rotate_top(t_list **stack, int number,
	void (*r)(t_list **), void (*rr)(t_list **))
{
	t_list	*current;
	int		size;
	int		counter;

	if (!*stack)
		return ;
	current = *stack;
	size = ft_lstsize(*stack);
	counter = 0;
	while (ctoi(current) != number && ++counter)
		current = current->next;
	if (counter > size / 2)
	{
		counter = size - counter;
		while (--counter)
			r(stack);
	}
	else
	{
		while (--counter + 2)
			rr(stack);
	}
}

void	rotate_bot(t_list **stack, int number,
	void (*r)(t_list **), void (*rr)(t_list **))
{
	t_list	*current;
	int		size;
	int		counter;

	if (!*stack)
		return ;
	current = *stack;
	size = ft_lstsize(*stack);
	counter = 0;
	while (ctoi(current) != number && ++counter)
		current = current->next;
	if (counter > size / 2)
	{
		counter = size - counter;
		while (counter--)
			r(stack);
	}
	else
	{
		while (--counter + 1)
			rr(stack);
	}
}

int	is_all_big_equal_than(t_list *stack, int number)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		if (ctoi(current) <= number)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_all_small_than(t_list *stack, int number)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		if (ctoi(current) >= number)
			return (0);
		current = current->next;
	}
	return (1);
}
