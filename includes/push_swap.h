/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:22:46 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/16 16:10:24 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	two_numbers_sort(t_stack **stack_a);
void	three_numbers_sort(t_stack **stack_a);
void	sort_5_4(t_stack **stack_a, t_stack **stack_b);
void	sort_6_plus(t_stack **stack_a, t_stack **stack_b, int range);
void	rra_sa(t_stack **stack_a);
void	sa_rra(t_stack **stack_a);
int		*sort_tab(int *tab, int size);
int		*storing_tab(t_stack *stack);
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b, int *tab, int range);
void	send_big_to_top(t_stack **stack);
int		get_biggest_nb(t_stack *stack);
t_stack	*stack_bottom(t_stack *stack);
t_stack	*second_to_last(t_stack *stack);
void	push(t_stack **source, t_stack **dest);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
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
void	free_str(char **str);
void	ft_error(char *message);
int		ft_lstsize(t_stack *stack_a);
void	ft_lstadd_back(t_stack **list, t_stack *new_element);
t_stack	*ft_lstnew(int input);
int		get_smallest_nb(t_stack *stack);
int		number_index(t_stack *stack_a, int x);
void	ft_putstr(char *str, int fd);
int		av_len(char **av);
void	check_digit(char	**str);
void	is_dup(t_stack *stack_a);
int		is_it_sorted(t_stack *stack);
void	fill_stack_a(t_stack **stack_a, char **sep);
void	push_swap(t_stack **stack_a, t_stack **stack_b);
char	*parse(char **av);
int		*in_array(t_stack *stack_a);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif