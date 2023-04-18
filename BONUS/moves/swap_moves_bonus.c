/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:41:24 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/17 21:41:38 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

// Swap the first 2 elements at the top of stack b
void	sb(t_stack **stack_b)
{
	swap(*stack_b);
}

// do sa and sb at the same time
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
}