/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:54:17 by dcavalei          #+#    #+#             */
/*   Updated: 2021/12/21 12:09:33 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	divide_stack(t_list **src, t_list **dest,
	void (*p)(t_list **, t_list **), void (*r)(t_list **), int pivot)
{
	t_list	*current;
	int		counter;

	counter = 0;
	if (!(*src))
		return (counter);
	while (!is_all_big_equal_than(*src, pivot))
	{
		current = ft_lstlast(*src);
		if (ctoi(current) <= pivot && ++counter)
			p(src, dest);
		else
			r(src);
	}
	return (counter);
}

int	divide_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		pivot;
	int		counter;

	counter = 0;
	pivot = get_pivot(*stack_b);
	if (!(*stack_b))
		return (0);
	while (*stack_b)
	{
		current = ft_lstlast(*stack_b);
		if (ctoi(current) >= pivot)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
		if (smaller_equal(*stack_b, pivot))
			break ;
	}
	return (counter);
}
