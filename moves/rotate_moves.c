/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:37:07 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/12 16:18:29 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//rotating the stack by moving the first element to the end of the stack.
void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = stack_bottom(*stack);
	tmp->next = NULL;
	last->next = tmp;
}

// Shift up all elements of stack a by 1
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n", 1);
}

// Shift up all elements of stack b by 1
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n", 1);
}

// do ra and rb at the same time.
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n", 1);
}
