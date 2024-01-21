/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:23:59 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/28 19:17:21 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *a)
{
	while (a)
	{
		if (a->cheapest)
			return (a);
		a = a->next;
	}
	return (a);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rr(a, b);
	update_index(a);
	update_index(b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b);
	update_index(a);
	update_index(b);
}

void	prep_a_for_push(t_stack **a, t_stack *top)
{
	if (top->above_median)
	{
		while (*a != top)
			ra(a);
	}
	else
	{
		while (*a != top)
			rra(a);
	}
}

void	prep_b_for_push(t_stack **b, t_stack *target)
{
	if (target->above_median)
	{
		while (*b != target)
			rb(b);
	}
	else
	{
		while (*b != target)
			rrb(b);
	}
}
