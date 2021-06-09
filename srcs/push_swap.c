/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:14:30 by dcavalei          #+#    #+#             */
/*   Updated: 2021/06/09 16:22:37 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	create_stacks(&stack_a, &stack_b, argc, argv);
	if (argc == 1 || argc == 2)
		close_program(&stack_a, &stack_b, 0);
	if (has_repeated_numbers(stack_a))
		close_program(&stack_a, &stack_b, 1);
	if (ft_lstsize(stack_a) <= 5)
		sort_5(&stack_a, &stack_b);
	else
		algorithm(&stack_a, &stack_b);
	close_program(&stack_a, &stack_b, 0);
}
