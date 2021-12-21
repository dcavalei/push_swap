/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:29:48 by dcavalei          #+#    #+#             */
/*   Updated: 2021/12/21 12:06:56 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_3_to_5(t_list **src, t_list **dest, int size)
{
	if (size != 3)
	{
		rotate_top(src, get_min(*src), ra, rra);
		pb(src, dest);
		rotate_top(src, get_min(*src), ra, rra);
		pb(src, dest);
	}
	if (ctoi(ft_lstlast(*src)) == get_max(*src))
		ra(src);
	if (ctoi(*src) != get_max(*src))
		rra(src);
	if (!is_sorted(*src))
		sa(*src);
	if (size != 3)
	{
		pa(src, dest);
		pa(src, dest);
	}
}

void	sort_5(t_list **src, t_list **dest)
{
	int	size;

	size = ft_lstsize(*src);
	if (is_sorted(*src))
		return ;
	else if (ft_lstsize(*src) == 2)
		sa(*src);
	else
		do_3_to_5(src, dest, size);
}

void	algorithm(t_list **stack_a, t_list **stack_b)
{
	int	moved;
	int	last;
	int	before_last;

	moved = 0;
	last = 0;
	before_last = 0;
	if (!(*stack_a) || is_sorted(*stack_a))
		return ;
	while (!is_sorted(*stack_a))
	{
		before_last = last;
		last = moved;
		moved = divide_stack(stack_a, stack_b, pb, ra, get_pivot(*stack_a));
	}
	moved += last + before_last;
	while (moved--)
	{
		rotate_top(stack_b, get_max(*stack_b), rb, rrb);
		pa(stack_a, stack_b);
	}
	while (*stack_b)
		divide_stack_b(stack_a, stack_b);
	algorithm(stack_a, stack_b);
}

int	smaller_equal(t_list *src, int pivot)
{
	while (src)
	{
		if (ctoi(src) > pivot)
			return (0);
		src = src->next;
	}
	return (1);
}

void	sort_low_efficient(t_list *sorted)
{
	t_list	*current;
	void	*tmp;

	if (!sorted)
		return ;
	current = sorted;
	while (current->next)
	{
		if (*((int *)(current->next->content)) > *((int *)(current->content)))
		{
			tmp = current->next->content;
			current->next->content = current->content;
			current->content = tmp;
			sort_low_efficient(sorted);
			break ;
		}
		current = current->next;
	}
}
