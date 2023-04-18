/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_moves_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:40:36 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/18 12:26:20 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*bottom;
	t_stack	*before_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	bottom = stack_bottom(*stack);
	before_last = second_to_last(*stack);
	tmp = *stack;
	*stack = bottom;
	(*stack)->next = tmp;
	before_last->next = NULL;
}

// shift down all the elements of the stack a by 1
void	rra(t_stack **a)
{
	rev_rotate(a);
}

// shift down all the elements of the stack b by 1
void	rrb(t_stack **b)
{
	rev_rotate(b);
}

// do rra and rrb at the same time
void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
