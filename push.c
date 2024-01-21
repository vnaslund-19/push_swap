/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:00:33 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/30 16:55:35 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!src)
		return (0);
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
	return (1);
}

void	pa(t_stack **a, t_stack **b)
{
	if (push(a, b))
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (push(b, a))
		write(1, "pb\n", 3);
}
