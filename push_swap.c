/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:35:16 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/18 13:59:43 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_it_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	fill_stack_a(t_stack **stack_a, char **sep)
{
	int		i;
	long	nb;

	i = 0;
	while (sep[i])
	{
		nb = ft_atoi(sep[i]);
		if (nb < INT_MIN || nb > INT_MAX)
		{
			ft_putstr("ERROR: check int min or max\n", 2);
			exit(1);
		}
		ft_lstadd_back(stack_a, ft_lstnew(nb));
		i++;
	}
	is_dup(*stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 2 && !is_it_sorted(*stack_a))
		two_numbers_sort(stack_a);
	else if (stack_size == 3)
		three_numbers_sort(stack_a);
	else if (stack_size > 3 && stack_size < 6 && !is_it_sorted(*stack_a))
		sort_5_4(stack_a, stack_b);
	else if (stack_size <= 100 && !is_it_sorted(*stack_a))
		sort_6_plus(stack_a, stack_b, 15);
	else if (stack_size <= 500 && !is_it_sorted(*stack_a))
		sort_6_plus(stack_a, stack_b, 36);
}

int	main(int ac, char **av)
{
	char	**splited;
	char	*nums;
	t_stack	*stack_b;
	t_stack	*stack_a;

	nums = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (ac > 2)
	{
		nums = parse2(av);
		splited = ft_split(nums, ' ');
		free(nums);
		check_digit(splited);
		fill_stack_a(&stack_a, splited);
		push_swap(&stack_a, &stack_b);
	}
}
