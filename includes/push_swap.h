/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:15:57 by dcavalei          #+#    #+#             */
/*   Updated: 2021/06/09 15:55:18 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/libft.h"

/*
**	srcs/algorithms/algorithms_01.c
*/

void	algorithm(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **src, t_list **dest);
void	sort_low_efficient(t_list *sorted);
int		smaller_equal(t_list *src, int pivot);

/*
**	srcs/algorithms/algorithms_01.c
*/

int		divide_stack(t_list **src, t_list **dest,
			void (*p)(t_list **, t_list **), void (*r)(t_list **), int pivot);
int		divide_stack_b(t_list **src, t_list **dest);

/*
**	srcs/operations/operations.c
*/

void	swap(t_list *stack);
void	push(t_list **src, t_list **dest);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

/*
**	srcs/operations/output_swap.c
*/

void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);

/*
**	srcs/operations/output_push.c
*/

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

/*
**	srcs/operations/output_rotate.c
*/

void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

/*
**	srcs/operations/output_reverse_rotate.c
*/

void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/*
**	srcs/utils/init.c
*/

/*
**	srcs/utils/stack_utils.c
*/

int		get_pivot(t_list *stack);
int		get_max(t_list *stack);
int		get_min(t_list *stack);
int		ctoi(t_list *stack);
int		is_sorted(t_list *stack);

/*
**	srcs/validate_funtions.c
*/

int		validate_input(char *str);
void	create_stacks(t_list **stack_a, t_list **stack_b,
			int argc, char **argv);
int		has_repeated_numbers(t_list *stack_a);
void	close_program(t_list **stack_a, t_list **stack_b, int status);

/*
**	srcs/debug.c
*/

void	rotate_top(t_list **stack, int number,
			void (*r)(t_list **), void (*rr)(t_list **));
void	rotate_bot(t_list **stack, int number,
			void (*r)(t_list **), void (*rr)(t_list **));
void	display_stacks(t_list *stack_a, t_list *stack_b);
int		is_all_big_equal_than(t_list *stack, int number);
int		is_all_small_than(t_list *stack, int number);

#endif
