/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:46:58 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/18 12:55:17 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	stack_a_fill(t_stack **stack_a, char **sep)
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
	input_dup(*stack_a);
}

void	input_dup(t_stack *stack_a)
{
	int	*arr;
	int	size;
	int	i;
	int	j;

	arr = array_in(stack_a);
	size = ft_lstsize(stack_a);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				ft_putstr("Error : duplicates", 2);
				exit (1);
			}
			j++;
		}
		i++;
	}
	free(arr);
}
