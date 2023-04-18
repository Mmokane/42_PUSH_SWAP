/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:37:00 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/17 21:44:17 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_bottom(t_stack *stack);
t_stack	*second_to_last(t_stack *stack);
void	push(t_stack **source, t_stack **dest);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack *stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);





#endif