/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:12:26 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/13 15:48:39 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// Shift down all elements of the stack by 1
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
	ft_putstr("rra\n", 1);
}

// shift down all the elements of the stack b by 1
void	rrb(t_stack **b)
{
	rev_rotate(b);
	ft_putstr("rrb\n", 1);
}

// do rra and rrb at the same time
void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putstr("rrr\n", 1);
}
