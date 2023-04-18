/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:10:30 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/18 14:14:48 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_actions(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0 && line)
		sa(stack_a);
	else if (line && ft_strcmp(line, "sb\n") == 0)
		sb(stack_b);
	else if (line && ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (line && ft_strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (line && ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (line && ft_strcmp(line, "rra\n") == 0)
		rra(stack_a);
	else if (line && ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b);
	else if (line && ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (line && ft_strcmp(line, "ra\n") == 0)
		ra(stack_a);
	else if (line && ft_strcmp(line, "rb\n") == 0)
		rb(stack_b);
	else if (line && ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b);
	else
		ft_putstr("Error\n", 2);
}

void	input_read(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_actions(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	sorted(t_stack *stack)
{
	if (stack)
	{
		while (stack->next != NULL)
		{
			if (stack->value > stack->next->value)
				return (0);
			stack = stack->next;
		}
		return (1);
	}
	return (0);
}

char	*parse(char **av)
{
	int		i;
	int		j;
	char	*numbers;

	i = 1;
	numbers = ft_strdup2("");
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (!av[i][j])
			ft_putstr("Error : parse function\n", 2);
		numbers = ft_strjoin(numbers, av[i]);
		numbers = ft_strjoin(numbers, " ");
		i++;
	}
	return (numbers);
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
		nums = parse(av);
		splited = ft_split(nums, ' ');
		free(nums);
		digit(splited);
		stack_a_fill(&stack_a, splited);
		input_read(&stack_a, &stack_b);
		if (sorted(stack_a) && stack_b == NULL)
			ft_putstr("OK\n", 1);
		else
			ft_putstr("KO\n", 1);
	}
}
