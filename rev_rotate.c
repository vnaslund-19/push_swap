/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:46:58 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/30 17:04:50 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rev_rotate(t_stack	**stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = ft_lastnode(stack);
	if (!first || !first->next)
		return (0);
	first->prev = last;
	last->next = first;
	last->prev->next = NULL;
	last->prev = NULL;
	*stack = last;
	return (1);
}

void	rra(t_stack	**a)
{
	if (rev_rotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack	**b)
{
	if (rev_rotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack	**a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
