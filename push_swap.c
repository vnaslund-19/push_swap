/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:50:15 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/31 17:16:22 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**nums;

	a = NULL;
	b = NULL;
	nums = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		init_stack(&a, nums, 1);
	}
	else
		init_stack(&a, argv + 1, 0);
	if (!stack_sorted(&a))
	{
		if (stack_len(&a) <= 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	ft_free_stack(&a, nums, 1);
}

void	init_stack(t_stack **a, char **av, int mem)
{
	long long	num;
	int			i;
	t_stack		*node;

	i = 0;
	while (av[i])
	{
		if (ft_syntax_error(av[i]))
			ft_errorhandler(a, av, mem);
		num = ft_atoi_longlong(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_errorhandler(a, av, mem);
		if (ft_repetition(a, num))
			ft_errorhandler(a, av, mem);
		node = ft_newnode((int)num);
		ft_nodeadd_back(a, node);
		i++;
	}
}
