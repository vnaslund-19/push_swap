/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:21:41 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/30 17:20:50 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max;
	t_stack	*first;

	first = *a;
	max = find_max(first);
	if (first == max)
		ra(a);
	else if (first->next == max)
		rra(a);
	first = *a;
	if (first->value > first->next->value)
		sa(a);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	a_len;

	a_len = stack_len(a);
	if (a_len-- > 3 && !stack_sorted(a))
		pb(a, b);
	if (a_len-- > 3 && !stack_sorted(a))
		pb(a, b);
	while (a_len-- > 3 && !stack_sorted(a))
	{
		init_nodes_a(a, b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(a, b);
		move_b_to_a(a, b);
	}
	update_index(a);
	move_min(a);
}

void	move_a_to_b(t_stack	**a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_a_for_push(a, cheapest_node);
	prep_b_for_push(b, cheapest_node->target_node);
	pb(a, b);
}

void	move_b_to_a(t_stack	**a, t_stack **b)
{
	prep_a_for_push(a, (*b)->target_node);
	pa(a, b);
}

void	move_min(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	while ((*a)->value != min->value)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}
