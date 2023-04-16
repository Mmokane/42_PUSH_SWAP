/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:46:40 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/15 21:51:19 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	send_big_to_top(t_stack **stack)
{
	int	i;
	int	size;

	while (1)
	{
		i = get_biggest_nb(*stack);
		size = ft_lstsize(*stack);
		if (i == 0)
			break ;
		if (i > size / 2)
			rrb(stack);
		else if (i <= size / 2)
			rb(stack);
	}
}

int	get_biggest_nb(t_stack *stack)
{
	int	y;
	int	i;
	int	max;

	i = 0;
	max = 0;
	y = stack->value;
	while (stack)
	{
		if (y < stack->value)
		{
			y = stack->value;
			max = i;
		}
		stack = stack->next;
		i++;
	}
	return (max);
}
