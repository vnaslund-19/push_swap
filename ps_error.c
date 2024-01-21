/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:06:57 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/31 13:51:34 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_repetition(t_stack **stack, int num)
{
	t_stack	*node;

	if (!stack)
		return (0);
	node = *stack;
	while (node)
	{
		if (node->value == num)
			return (1);
		node = node->next;
	}
	return (0);
}

int	ft_syntax_error(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-' && !(str[i] >= '0' && str[i] <= '9'))
		return (1);
	if (str[0] == '-' && str[1] == '\0')
		return (1);
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}
	return (0);
}

long long	ft_atoi_longlong(const char *str)
{
	int			i;
	int			sign;
	long long	num;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}

void	ft_errorhandler(t_stack **a, char **av, int mem)
{
	ft_free_stack(a, av, mem);
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

void	ft_free_stack(t_stack **a, char **nums, int mem)
{
	t_stack	*node;
	t_stack	*temp;
	int		i;

	node = *a;
	if (!node)
		return ;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*a = NULL;
	i = 0;
	if (!mem)
		return ;
	if (nums)
	{
		while (nums[i])
			free(nums[i++]);
	}
	free(nums);
	nums = NULL;
}
