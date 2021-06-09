/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:22:08 by dcavalei          #+#    #+#             */
/*   Updated: 2021/06/09 16:22:42 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_valid_user_input(char *line);
void	apply_user_input(t_list **stack_a, t_list **stack_b, char *line);

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;

	create_stacks(&stack_a, &stack_b, argc, argv);
	if (argc == 1)
		exit(0);
	if (has_repeated_numbers(stack_a))
		close_program(&stack_a, &stack_b, 1);
	while (ft_get_next_line(0, &line))
	{
		if (!is_valid_user_input(line))
		{
			free(line);
			close_program(&stack_a, &stack_b, 1);
		}
		apply_user_input(&stack_a, &stack_b, line);
		free(line);
	}
	free(line);
	if (!stack_b && is_sorted(stack_a))
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	close_program(&stack_a, &stack_b, 0);
}

int	is_valid_user_input(char *line)
{
	if (!ft_strncmp(line, "sa", 3) || !ft_strncmp(line, "sb", 3)
		|| !ft_strncmp(line, "ss", 3)
		|| !ft_strncmp(line, "ra", 3) || !ft_strncmp(line, "rb", 3)
		|| !ft_strncmp(line, "rr", 3)
		|| !ft_strncmp(line, "rra", 4) || !ft_strncmp(line, "rrb", 4)
		|| !ft_strncmp(line, "rrr", 4)
		|| !ft_strncmp(line, "pa", 3) || !ft_strncmp(line, "pb", 3))
		return (1);
	return (0);
}

static void	apply_user_input_helper(t_list **stack_a,
		t_list **stack_b, char *line)
{
	if (!ft_strncmp(line, "rra", 3))
		reverse_rotate(stack_a);
	else if (!ft_strncmp(line, "rrb", 3))
		reverse_rotate(stack_b);
	else if (!ft_strncmp(line, "rrr", 3))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else if (!ft_strncmp(line, "pa", 2))
		push(stack_b, stack_a);
	else if (!ft_strncmp(line, "pb", 2))
		push(stack_a, stack_b);
}

void	apply_user_input(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strncmp(line, "sa", 2))
		swap(*stack_a);
	else if (!ft_strncmp(line, "sb", 2))
		swap(*stack_b);
	else if (!ft_strncmp(line, "ss", 2))
	{
		swap(*stack_a);
		swap(*stack_b);
	}
	else if (!ft_strncmp(line, "ra", 2))
		rotate(stack_a);
	else if (!ft_strncmp(line, "rb", 2))
		rotate(stack_b);
	else if (!ft_strncmp(line, "rr", 2))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else
		apply_user_input_helper(stack_a, stack_b, line);
}
