/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:27:24 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/16 14:47:01 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// swap the value of the first 2 elements

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

// Swap the first 2 elements at the top of stack a
void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n", 1);
}

// Swap the first 2 elements at the top of stack b
void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n", 1);
}

// do sa and sb at the same time
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n", 1);
}
