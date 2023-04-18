/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:37:00 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/18 14:13:55 by mmokane          ###   ########.fr       */
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
int		ft_strcmp(char *s1, char *s2);
void	check_actions(t_stack **stack_a, t_stack **stack_b, char *line);
void	input_read(t_stack **stack_a, t_stack **stack_b);
int		sorted(t_stack *stack);
char	*parse(char **av);
int		main(int ac, char **av);
void	ft_putstr(char *str, int fd);
char	**ft_split(char const *s, char c);
void	digit(char	**str);
void	digit_error(void);
int		ft_isdigit(int c);
void	stack_a_fill(t_stack **stack_a, char **sep);
void	input_dup(t_stack *stack_a);
int		ft_lstsize(t_stack *stack_a);
void	ft_lstadd_back(t_stack **list, t_stack *new_element);
t_stack	*ft_lstnew(int input);
int		get_smallest_nb(t_stack *stack);
int		number_index(t_stack *stack_a, int x);
int		*array_in(t_stack *stack_a);
long	ft_atoi(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_strchr(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup2(char *s);

#endif