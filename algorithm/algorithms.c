/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:51:11 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/16 16:01:02 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sort two numbers
void	two_numbers_sort(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

// check the screenshot for more :-)
void	three_numbers_sort(t_stack **stack_a)
{
	if (((*stack_a)->value < (*stack_a)->next->value)
		&& ((*stack_a)->value < (*stack_a)->next->next->value))
	{
		if ((*stack_a)->next->value > (*stack_a)->next->next->value)
			rra_sa(stack_a);
	}
	else if (((*stack_a)->value > (*stack_a)->next->value)
		&& ((*stack_a)->value < (*stack_a)->next->next->value))
		sa(stack_a);
	else if (((*stack_a)->value < (*stack_a)->next->value)
		&& ((*stack_a)->value > (*stack_a)->next->next->value))
		rra(stack_a);
	else if (((*stack_a)->value > (*stack_a)->next->value)
		&& ((*stack_a)->value > (*stack_a)->next->next->value))
	{
		if ((*stack_a)->next->value < (*stack_a)->next->next->value)
			ra(stack_a);
		else
			sa_rra(stack_a);
	}
}

void	sort_5_4(t_stack **stack_a, t_stack **stack_b)
{
	int	x;

	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_a) < 6)
	{
		x = get_smallest_nb(*stack_a);
		while (x != (*stack_a)->value)
		{
			if (number_index(*stack_a, x) > ft_lstsize(*stack_a) / 2)
				rra(stack_a);
			else
				ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	three_numbers_sort(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

// sort it by using the half stack tech, and using stack b
// void	sort_5_4(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	x;

// 	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_a) < 6)
// 	{
// 		x = get_smallest_nb(*stack_a);
// 		while (x != (*stack_a)->value)
// 		{
// 			if (number_index(*stack_a, x) > ft_lstsize(*stack_a) / 2)
// 				rra(stack_a);
// 			else
// 				ra(stack_a);
// 		}
// 		pb(stack_a, stack_b);
// 	}
// 	three_numbers_sort(stack_a);
// 	while (*stack_b)
// 		pa(stack_a, stack_b);
// }

// we sort it using a reference table, so we can split the numbers by its range
void	sort_6_plus(t_stack **stack_a, t_stack **stack_b, int range)
{
	int	*tab;

	tab = storing_tab(*stack_a);
	push_a_to_b(stack_a, stack_b, tab, range);
	while (*stack_b)
	{
		send_big_to_top(stack_b);
		pa(stack_a, stack_b);
	}
	free(tab);
}
