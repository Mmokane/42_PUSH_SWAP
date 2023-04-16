/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:09:23 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/15 21:51:14 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra_sa(t_stack **stack_a)
{
	rra(stack_a);
	sa(stack_a);
}

void	sa_rra(t_stack **stack_a)
{
	sa(stack_a);
	rra(stack_a);
}

int	*sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	*storing_tab(t_stack *stack)
{
	int	*tab;
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(stack);
	tab = malloc((size) * sizeof(int));
	while (stack)
	{
		tab[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (sort_tab(tab, size));
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b, int *tab, int range)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->value <= tab[i])
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->value > tab[i]
			&& (*stack_a)->value <= tab[range + i])
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}
