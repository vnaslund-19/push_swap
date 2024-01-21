/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:51:18 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/31 17:15:59 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
}				t_stack;

//Error handling
int			ft_repetition(t_stack **stack, int num);
int			ft_syntax_error(char *str);
void		ft_errorhandler(t_stack **a, char **av, int mem);
long long	ft_atoi_longlong(const char *str);
void		ft_free_stack(t_stack **a, char **nums, int mem);

//Create stack
void		init_stack(t_stack **a, char **av, int mem);
void		ft_nodeadd_back(t_stack **stack, t_stack *new);
t_stack		*ft_newnode(int num);
t_stack		*ft_lastnode(t_stack **stack);

// Sorting operations
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);
void		ra(t_stack	**a);
void		rb(t_stack	**b);
void		rr(t_stack	**a, t_stack **b);
void		rra(t_stack	**a);
void		rrb(t_stack	**b);
void		rrr(t_stack	**a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);

// General utils
t_stack		*find_max(t_stack *stack);
t_stack		*find_min(t_stack *stack);
int			stack_len(t_stack **stack);
int			stack_sorted(t_stack **stack);

// Algorithm
void		sort_three(t_stack **a);
void		sort_stacks(t_stack **a, t_stack **b);
void		move_a_to_b(t_stack	**a, t_stack **b);
void		move_b_to_a(t_stack	**a, t_stack **b);
void		move_min(t_stack **a);

// Algorithm utils
t_stack		*get_cheapest(t_stack *a);
void		rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void		rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void		prep_a_for_push(t_stack **a, t_stack *top);
void		prep_b_for_push(t_stack **b, t_stack *target);

// Init a nodes
void		init_nodes_a(t_stack **a, t_stack **b);
void		update_index(t_stack **stack);
void		set_target_a(t_stack *a, t_stack *b);
void		push_cost_calc_a(t_stack **a, t_stack **b);
void		cheapest_node(t_stack	**stack);

// Init b nodes
void		init_nodes_b(t_stack **a, t_stack **b);
void		set_target_b(t_stack *a, t_stack *b);

#endif
