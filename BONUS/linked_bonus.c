/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:46:57 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/17 21:47:17 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_lstsize(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_stack **list, t_stack *new_element)
{
	t_stack	*content;

	content = *list;
	if (!*list)
		*list = new_element;
	else
	{
		while (content -> next)
			content = content -> next;
		content -> next = new_element;
	}
}

t_stack	*ft_lstnew(int input)
{
	t_stack	*head;

	head = (t_stack *)malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->value = input;
	head->next = NULL;
	return (head);
}

int	get_smallest_nb(t_stack *stack)
{
	int	x;

	x = stack->value;
	while (stack)
	{
		if (x > stack->value)
			x = stack->value;
		stack = stack->next;
	}
	return (x);
}

int	number_index(t_stack *stack_a, int x)
{
	int	i;

	i = 0;
	while (stack_a->value != x)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}