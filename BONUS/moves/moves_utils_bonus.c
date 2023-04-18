/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:42:03 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/17 21:42:14 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*second_to_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}