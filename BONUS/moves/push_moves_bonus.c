/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:39:41 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/17 21:40:11 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack **source, t_stack **dest)
{
	t_stack	*tmp;

	if (*source == NULL)
		return ;
	tmp = (*source)->next;
	(*source)->next = *dest;
	*dest = *source;
	*source = tmp;
}

// push top of stack a to stack b
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
}

// pussh top of stack b to stack a
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
}