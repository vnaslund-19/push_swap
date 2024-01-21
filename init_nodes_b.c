/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:37:18 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/31 14:31:11 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_b(t_stack **a, t_stack **b)
{
	update_index(a);
	update_index(b);
	set_target_b(*a, *b);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*target_node;
	long	closest_bigger_value;

	while (b)
	{
		closest_bigger_value = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->value > b->value
				&& current->value < closest_bigger_value)
			{
				closest_bigger_value = current->value;
				target_node = current;
			}
			current = current->next;
		}
		if (closest_bigger_value == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
