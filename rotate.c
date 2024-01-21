/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:18:10 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/30 17:04:52 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack	**stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	first = *stack;
	second = first->next;
	last = ft_lastnode(stack);
	if (!first || !first->next)
		return (0);
	first->next->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	*stack = second;
	return (1);
}

void	ra(t_stack	**a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack	**b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack	**a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
