/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_general_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:37:10 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/28 20:21:43 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	if (!node)
		return (1);
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	stack_len(t_stack **stack)
{
	t_stack	*node;
	int		i;

	i = 0;
	node = *stack;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*ret;
	int		max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->value >= max)
		{
			max = stack->value;
			ret = stack;
		}
		stack = stack->next;
	}
	return (ret);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*ret;
	int		min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->value <= min)
		{
			min = stack->value;
			ret = stack;
		}
		stack = stack->next;
	}
	return (ret);
}
