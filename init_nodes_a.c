/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:39:47 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/28 20:17:47 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_a(t_stack **a, t_stack **b)
{
	update_index(a);
	update_index(b);
	set_target_a(*a, *b);
	push_cost_calc_a(a, b);
	cheapest_node(a);
}

void	update_index(t_stack **stack)
{
	int		i;
	int		median;
	t_stack	*node;

	i = 0;
	if (!*stack)
		return ;
	node = *stack;
	median = stack_len(stack) / 2;
	while (node)
	{
		node->index = i;
		if (i <= median)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
		i++;
	}
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*target_node;
	int		closest_smaller_value;

	while (a)
	{
		closest_smaller_value = INT_MIN;
		current = b;
		while (current)
		{
			if (current->value < a->value
				&& current->value > closest_smaller_value)
			{
				closest_smaller_value = current->value;
				target_node = current;
			}
			current = current->next;
		}
		if (closest_smaller_value == INT_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	push_cost_calc_a(t_stack **a, t_stack **b)
{
	t_stack	*a_node;
	int		a_len;
	int		b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	a_node = *a;
	while (a_node)
	{
		a_node->push_cost = a_node->index;
		if (!(a_node->above_median))
			a_node->push_cost = a_len - a_node->index;
		if (a_node->target_node->above_median)
			a_node->push_cost += a_node->target_node->index;
		else
			a_node->push_cost += b_len - a_node->target_node->index;
		a_node = a_node->next;
	}
}

void	cheapest_node(t_stack	**stack)
{
	t_stack	*cheapest_node;
	t_stack	*node_ptr;
	int		min_push_cost;

	node_ptr = *stack;
	if (!node_ptr)
		return ;
	min_push_cost = INT_MAX;
	while (node_ptr)
	{
		if (node_ptr->push_cost < min_push_cost)
		{
			min_push_cost = node_ptr->push_cost;
			cheapest_node = node_ptr;
		}
		node_ptr = node_ptr->next;
	}
	cheapest_node->cheapest = true;
}
