/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:49:19 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/16 15:35:21 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	digit_error(void)
{
	ft_putstr("Error : digit function\n", 2);
	exit(1);
}

int	*in_array(t_stack *stack_a)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(4 * ft_lstsize(stack_a));
	while (stack_a)
	{
		arr[i] = stack_a->value;
		stack_a = stack_a->next;
		i++;
	}
	return (arr);
}

void	is_dup(t_stack *stack_a)
{
	int	*arr;
	int	size;
	int	i;
	int	j;

	arr = in_array(stack_a);
	size = ft_lstsize(stack_a);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				ft_putstr("Error : dup function", 2);
			j++;
		}
		i++;
	}
	free(arr);
}

void	check_digit(char	**str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
		{
			if (!ft_isdigit(str[i][++j]))
				digit_error();
		}
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				digit_error();
			j++;
		}
		i++;
	}
}

char	*parse(char **av)
{
	int		i;
	int		j;
	char	*numbers;

	i = 1;
	numbers = "";
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
