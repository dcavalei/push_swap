/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:29:19 by dcavalei          #+#    #+#             */
/*   Updated: 2021/06/01 16:03:57 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	t_list	*current;
	void	*tmp;
	int		size;
	int		i;

	if (!stack)
		return ;
	size = ft_lstsize(stack);
	if (size < 2)
		return ;
	i = -1;
	current = stack;
	while (++i < size - 2)
		current = current->next;
	tmp = current->content;
	current->content = current->next->content;
	current->next->content = tmp;
}

void	push(t_list **src, t_list **dest)
{
	t_list	*current;
	t_list	*node;
	int		src_size;
	int		i;

	src_size = ft_lstsize(*src);
	if (!src_size)
		return ;
	current = *src;
	i = 0;
	while (++i < src_size - 1)
		current = current->next;
	if (src_size == 1)
	{
		node = current;
		*src = NULL;
	}
	else
	{
		node = current->next;
		current->next = NULL;
	}
	ft_lstadd_back(dest, node);
}

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*new_head;
	int		size;
	int		i;

	size = ft_lstsize(*stack);
	if (!size || size == 1)
		return ;
	tmp = *stack;
	i = 0;
	while (++i < size - 1)
		tmp = tmp->next;
	new_head = tmp->next;
	tmp->next = NULL;
	new_head->next = *stack;
	*stack = new_head;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*new_head;
	int		size;

	size = ft_lstsize(*stack);
	if (!size || size == 1)
		return ;
	new_head = (*stack)->next;
	tmp = *stack;
	*stack = new_head;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}
